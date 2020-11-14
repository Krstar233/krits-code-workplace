using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class FoodMaker : MonoBehaviour {

    public int xlimit;//（0,0）出发蛇往右走在地图上的最远步数
    public int ylimit;// 往上走的最远步数
    public int xoffset; // 往左走相对往右走的偏移量(步数)
    private int step; // 蛇每走一步移动的距离
    public Sprite[] foodSprites;
    public GameObject foodPrefab;
    private Transform foodHolderTram;
    public GameObject rewardPrefab;

    private static FoodMaker _instance;
    public static FoodMaker Instance
    {
        get
        {
            return _instance;
        }
    }

    private void Awake()
    {
        _instance = this;
    }

    public void MakeFood(bool addReward)
    {
        int index = Random.Range(0, foodSprites.Length);
        GameObject food = Instantiate(foodPrefab);
        food.GetComponent<Image>().sprite = foodSprites[index];
        int x = Random.Range(-xlimit + xoffset, xlimit+1) * step;
        int y = Random.Range(-ylimit, ylimit+1) * step;
        food.transform.SetParent(foodHolderTram, false);
        food.transform.localPosition = new Vector3(x, y, 0);
        if (addReward)
        {
            GameObject reward = Instantiate(rewardPrefab);
            x = Random.Range(-xlimit + xoffset, xlimit+1) * step;
            y = Random.Range(-ylimit, ylimit+1) * step;
            reward.transform.SetParent(foodHolderTram, false);
            reward.transform.localPosition = new Vector3(x, y, 0);
        }
    }
    // Use this for initialization
    void Start()
    {
        int up = 275;
        int right = 475;
        int offset = 200;

        step = GameObject.Find("SnakeHead").GetComponent<SnakeHead>().step;

        ylimit = up / step;
        xlimit = right / step;
        xoffset = offset / step;

        foodHolderTram = GameObject.Find("FoodHolder").transform;
        MakeFood(false);
    }



}
