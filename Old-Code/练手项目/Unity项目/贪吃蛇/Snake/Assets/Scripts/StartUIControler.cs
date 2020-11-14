using UnityEngine;
using System.Collections;
using UnityEngine.UI;

public class StartUIControler : MonoBehaviour {
    public Text lastText;
    public Text bestText;
    public Toggle blue;
    public Toggle yellow;
    public Toggle border;
    public Toggle noBorder;


    void Awake()
    {
        lastText.text = "上次：长度 " + PlayerPrefs.GetInt("lastl", 0) + " 分数 " + PlayerPrefs.GetInt("lasts", 0);
        bestText.text = "最佳：长度 " + PlayerPrefs.GetInt("bestl", 0) + " 分数 " + PlayerPrefs.GetInt("bests", 0);
    }

    void Start ()
    {
        // 根据用户存储的信息 初始化 4 个勾选框
        if (PlayerPrefs.GetString("sh", "sh01") == "sh01")
        {
            blue.isOn = true;
        }
        else
        {
            yellow.isOn = true;
        }
        
        if (PlayerPrefs.GetInt("border", 1) == 1)
        {
            border.isOn = true;
        }
        else
        {
            noBorder.isOn = true;
        }

	}

    //四个勾选框对应的函数：
    public void Blue(bool isOn)
    {
        if (isOn)
        {
            //存储用户信息
            PlayerPrefs.SetString("sh", "sh01");
            PlayerPrefs.SetString("sb01", "sb0101");
            PlayerPrefs.SetString("sb02", "sb0102");
        }
    }
    public void Yellow(bool isOn)
    {
        if (isOn)
        {
            PlayerPrefs.SetString("sh", "sh02");
            PlayerPrefs.SetString("sb01", "sb0201");
            PlayerPrefs.SetString("sb02", "sb0202");
        }
    }
    public void Border(bool isOn)
    {
        if (isOn)
        {
            PlayerPrefs.SetInt("border", 1);
        }
    }
    public void NoBorder(bool isOn)
    {
        if (isOn)
        {
            PlayerPrefs.SetInt("border", 0);
        }
    }


    public void StartGame()
    {
        UnityEngine.SceneManagement.SceneManager.LoadScene(1);
    }

}
