using UnityEngine;
using UnityEngine.UI;
using System.Collections;

public class MainUIControler : MonoBehaviour {

    public Text msgText;
    public Text scoreText;
    public Text lengthText;
    public Image bgImage;
    public Image pauseImage;
    public Image homeImage;
    public Sprite[] PauseSprites = new Sprite[2];
    private int score = 0;
    private int length = 0;
    private Color tempColor;
    private bool isPause = false;
    private bool hasBorder;

    public bool IsPause{ get { return isPause; } }
    public int Score { get { return score; } }
    public int Length { get { return length; } }
    public bool HasBorder { get { return hasBorder; } }

    private static MainUIControler _instance; //单例
    public static MainUIControler Instance
    {
        get
        {
            return _instance;
        }
    }

    void Awake()
    {
        _instance = this;
        
    }

    void Start()
    {
        if (PlayerPrefs.GetInt("border", 1) == 1)
            hasBorder = true;
        else hasBorder = false;

        if (!hasBorder)
        {
            foreach (Transform t in bgImage.gameObject.transform)
            {
                t.gameObject.GetComponent<Image>().enabled = false;
            }
        }
    }
    public void updateUI(int s = 5, int l = 1)
    {
        score += s;
        length += l;
        scoreText.text = "得 分 ：\n" + Score;
        lengthText.text = "长 度 ：\n" + Length;

        if (Score >= 1100)
        {
            ColorUtility.TryParseHtmlString("#FFDACCFF", out tempColor);
            bgImage.color = tempColor;
            msgText.text = "无 尽 阶 段";
        }
        else if (Score >= 900)
        {
            ColorUtility.TryParseHtmlString("#FFF3CCFF", out tempColor);
            bgImage.color = tempColor;
            msgText.text = "阶 段 " + 5;
        }
        else if (Score >= 700)
        {
            ColorUtility.TryParseHtmlString("#EBFFCCFF", out tempColor);
            bgImage.color = tempColor;
            msgText.text = "阶 段 " + 4;
        }
        else if (Score >= 500)
        {
            ColorUtility.TryParseHtmlString("#CCEEDBFF", out tempColor);
            bgImage.color = tempColor;
            msgText.text = "阶 段 " + 3;
        }
        else if (Score >= 300)
        {
            ColorUtility.TryParseHtmlString("#CCEEFFFF", out tempColor);
            bgImage.color = tempColor;
            msgText.text = "阶 段 " + 2;
        }
    }
    public void Pause()
    {
        if (!isPause)
        {
            Time.timeScale = 0;
            pauseImage.sprite = PauseSprites[1];
            isPause = true;
        }
        else
        {
            Time.timeScale = 1;
            pauseImage.sprite = PauseSprites[0];
            isPause = false;
        }
    }
	public void Home()
    {
        UnityEngine.SceneManagement.SceneManager.LoadScene(0);
    }
}
