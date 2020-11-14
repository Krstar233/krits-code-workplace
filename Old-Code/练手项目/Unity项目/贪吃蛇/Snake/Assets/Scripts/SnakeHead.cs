using UnityEngine;
using System.Collections;
using System.Collections.Generic;
using UnityEngine.UI;

public class SnakeHead : MonoBehaviour {
    public int step; //蛇头一步移动的距离
    private int x; //下一步水平方向移动的距离
    private int y; //下一步竖直方向移动的距离

    public float repeatTime;
    public GameObject Snakebody;

    private List<Transform> bodys = new List<Transform>();
    private Vector3 headPosition;

    public Sprite[] bodySprites = new Sprite[2]; //蛇身贴图
    //private Transform canvas; //使用canvas作为父物体有bug，可能会导致食物显示在蛇身的下方，而被遮住；
    private Transform snakeBodyTransform; //替代方案:使用SnakeBody作为父物体

    private bool isDie = false;
    public GameObject dieEffect;

    //音源
    public AudioClip dieAudio;
    public AudioClip eatAudio;


    void Awake()
    {
        //canvas = GameObject.Find("Canvas").transform;
        snakeBodyTransform = GameObject.Find("SnakeBody").transform;

        //加载资源文件以及设置模式
        gameObject.GetComponent<Image>().sprite = Resources.Load<Sprite>(PlayerPrefs.GetString("sh", "sh01"));//加载蛇头贴图
        bodySprites[0] = Resources.Load<Sprite>(PlayerPrefs.GetString("sb01", "sb0101"));//加载蛇身贴图
        bodySprites[1] = Resources.Load<Sprite>(PlayerPrefs.GetString("sb02", "sb0102"));

    }
    void Move()
    {
        headPosition = gameObject.transform.localPosition;
        gameObject.transform.localPosition = new Vector3(headPosition.x + x, headPosition.y + y, headPosition.z);

        //蛇身移动
        for (int i = bodys.Count - 2; i >= 0; i--)
        {
            bodys[i + 1].localPosition = bodys[i].localPosition;
        }
        if (bodys.Count > 0)
            bodys[0].localPosition = headPosition;


    }
    void Grow()
    {
        int index = bodys.Count % 2;
        GameObject newbody = Instantiate(Snakebody);
        newbody.transform.localPosition = new Vector3(2000, 2000, 0);
        newbody.GetComponent<Image>().sprite = bodySprites[index];
        newbody.transform.SetParent(snakeBodyTransform, false);
        bodys.Add(newbody.transform);
    }
    void Start () {
        InvokeRepeating("Move", 0, repeatTime);
        x = 0; y = step;
        isDie = false;
    }
	void Update () {
        if (MainUIControler.Instance.IsPause || isDie) //暂停或者死亡之后不接受任何按键
        {
            return;
        }

        if (Input.GetKeyDown(KeyCode.Space))
        {
            CancelInvoke();
            InvokeRepeating("Move", 0, repeatTime - 0.2f);
        }
        if (Input.GetKeyUp(KeyCode.Space))
        {
            CancelInvoke();
            InvokeRepeating("Move", 0, repeatTime);
        }
        if (Input.GetKey(KeyCode.W) && y != -step)
        {
            x = 0; y = step;
            gameObject.transform.localRotation = Quaternion.Euler(0, 0, 0);
        }
        if (Input.GetKey(KeyCode.A) && x != step)
        {
            x = -step; y = 0;
            gameObject.transform.localRotation = Quaternion.Euler(0, 0, 90);
        }
        if (Input.GetKey(KeyCode.S) && y != step)
        {
            x = 0; y = -step;
            gameObject.transform.localRotation = Quaternion.Euler(0, 0, 180);
        }
        if (Input.GetKey(KeyCode.D) && x != -step)
        {
            x = step; y = 0;
            gameObject.transform.localRotation = Quaternion.Euler(0, 0, -90);
        }
    }
    void Die()
    {
        //播放音源
        AudioSource.PlayClipAtPoint(dieAudio, Vector3.zero);

        CancelInvoke();
        GameObject effect = Instantiate(dieEffect);
        effect.transform.position = new Vector3(transform.position.x, transform.position.y, 1);
        isDie = true;

        //数据存储
        PlayerPrefs.SetInt("lastl", MainUIControler.Instance.Length);
        PlayerPrefs.SetInt("lasts", MainUIControler.Instance.Length);

        if (PlayerPrefs.GetInt("bests",0) < MainUIControler.Instance.Score)
        {
            PlayerPrefs.SetInt("bestl", MainUIControler.Instance.Length);
            PlayerPrefs.SetInt("bests", MainUIControler.Instance.Score);
        }

        //启动协程
        StartCoroutine(GameOver(2.5f));
    }
    IEnumerator GameOver(float t)
    {
        yield return new WaitForSeconds(t);
        //print("Die!!!!!!!!!!!!!");
        UnityEngine.SceneManagement.SceneManager.LoadScene(1);
    }

    private void OnTriggerEnter2D(Collider2D collision)
    {
        if (collision.tag == "Food")
        {
            //播放音源
            AudioSource.PlayClipAtPoint(eatAudio, Vector3.zero + new Vector3(0,0,-3)); // 声音太大声了，音源位置要后移些

            Destroy(collision.gameObject);
            FoodMaker.Instance.MakeFood(Random.Range(0,100) < 20);
            Grow();
            MainUIControler.Instance.updateUI();
            //print("food");
        }
        else if (collision.tag == "Reward")
        {
            //播放音源
            AudioSource.PlayClipAtPoint(eatAudio, Vector3.zero + new Vector3(0, 0, -3));
            Destroy(collision.gameObject);
            Grow();
            MainUIControler.Instance.updateUI(Random.Range(5,16)*10);
            //print("reward");
        }
        else if (collision.tag == "Body")
        {
            Die();
            //print("Die");
        }
        else
        {
            if (MainUIControler.Instance.HasBorder)
            {
                Die();
            }
            else
            {
                switch (collision.name)
                {
                    case "Up":
                        //print("up");
                        transform.localPosition = new Vector3(transform.localPosition.x, -transform.localPosition.y + step, 0);
                        break;
                    case "Down":
                        //print("down");
                        transform.localPosition = new Vector3(transform.localPosition.x, -transform.localPosition.y - step, 0);
                        break;
                    case "Left":
                        //print("left");
                        transform.localPosition = new Vector3(-transform.localPosition.x + 200 - step, transform.localPosition.y, 0);
                        break;
                    case "Right":
                        //print("right");
                        transform.localPosition = new Vector3(-transform.localPosition.x + 200 + step, transform.localPosition.y, 0);
                        break;
                }
            }
        }
    }
}
