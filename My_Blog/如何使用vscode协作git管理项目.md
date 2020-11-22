# 如何使用vscode协作git管理项目

## 环境准备
- 操作系统：windows10 x64（演示）
- git [下载地址](https://git-scm.com/downloads) [镜像下载](http://npm.taobao.org/mirrors/git-for-windows/)
- vscode [下载地址](https://code.visualstudio.com/)

## 操作步骤
### 安装Git
在git官网，选择Windows平台下的最新版本[下载](https://git-scm.com/downloads)，但是官网下载可能出现网页无法打开的问题，这里也提供[国内镜像下载地址](http://npm.taobao.org/mirrors/git-for-windows/)。

打开下载好的安装包，如没有特殊设置，一直“next”即可。
[![DujTL6.png](https://s3.ax1x.com/2020/11/19/DujTL6.png)](https://imgchr.com/i/DujTL6)
**完成之后记得重启计算机，使得Git在Windows下的环境变量生效。**

### 注册Github并添加一个远程仓库
- 注册一个账号
打开[Github](https://github.com/)的官网，在右上角点击“sign up”进行注册。

- 创建一个远程仓库
登录你的Github账户，在右上角点击你自己的头像图标打开下拉菜单，然后选择“Your repositories”
[![DmSoIe.png](https://s3.ax1x.com/2020/11/18/DmSoIe.png)](https://imgchr.com/i/DmSoIe)
在打开的页面中点击“New”按钮新建远程仓库。
[![DmpkMq.png](https://s3.ax1x.com/2020/11/18/DmpkMq.png)](https://imgchr.com/i/DmpkMq)
输入仓库名，比如“MyProject”，然后在选择默认新建一个“README”文件，最后点击“Create Repository”。
[![DmptoD.png](https://s3.ax1x.com/2020/11/18/DmptoD.png)](https://imgchr.com/i/DmptoD)
仓库主页：
[![DmpDyt.png](https://s3.ax1x.com/2020/11/18/DmpDyt.png)](https://imgchr.com/i/DmpDyt)
可以看到我们的仓库中默认添加了一个标题为“MyProject”的README文件。


### 添加ssh key到GitHub
- 生成ssh key:
    在桌面或者文件管理器的空白处按鼠标右键，选择“Git Bash Here”。
    [![DuzNdK.png](https://s3.ax1x.com/2020/11/19/DuzNdK.png)](https://imgchr.com/i/DuzNdK)
    之后会弹出一个Git的黑色窗口，在这里可以输入命令行：
    [![DuzWFS.png](https://s3.ax1x.com/2020/11/19/DuzWFS.png)](https://imgchr.com/i/DuzWFS)
    输入指令，进入.ssh文件夹
    ```
    cd ~/.ssh/
    ```
    如果提示“No such file or directory”,可以手动创建一个.ssh文件夹：
    ```
    mkdir ~/.ssh
    ```
    配置全局的name和email，这里是的你github的name和email：
    ```
    git config --global user.name "xxx"
 
    git config --global user.email "xxx@xx.com"
    ```
    输入指令，生成ssh key：
    ```
    ssh-keygen -t rsa -C "xxx@xx.com"
    ```
    之后会提示一些信息，一直按回车即可。
    [![DKPdv4.png](https://s3.ax1x.com/2020/11/19/DKPdv4.png)](https://imgchr.com/i/DKPdv4)

- 在GitHub上添加自己的ssh key
    在Git Bash中输入指令，查看本机生成的ssh key：
    ```
    cat ~/.ssh/id_rsa.pub
    ```
    [![DKPTat.png](https://s3.ax1x.com/2020/11/19/DKPTat.png)](https://imgchr.com/i/DKPTat)
    打开你的Github主页，点击右上角你的头像图标展开下拉菜单，选择“setting”
    [![DKiVsJ.png](https://s3.ax1x.com/2020/11/19/DKiVsJ.png)](https://imgchr.com/i/DKiVsJ)
    在打开页面的左侧栏中选择“SSH and GPG keys”,在展开的右侧页面中选择“New SSH key”
    [![DKiNdI.png](https://s3.ax1x.com/2020/11/19/DKiNdI.png)](https://imgchr.com/i/DKiNdI)
    在展开的页面中，把之前找到的ssh key复制上去，点击“Add SSH key”
    [![DKiDSS.png](https://s3.ax1x.com/2020/11/19/DKiDSS.png)](https://imgchr.com/i/DKiDSS)
    回到刚刚的页面，发现ssh key已经添加成功了。
    [![DKibwR.png](https://s3.ax1x.com/2020/11/19/DKibwR.png)](https://imgchr.com/i/DKibwR)

### 克隆远程仓库到本地
打开Github上的仓库页面，点击“Code”图标，在下拉菜单中选择“SSH”方式，将图示的代码串复制下来:
[![DKEDNn.png](https://s3.ax1x.com/2020/11/19/DKEDNn.png)](https://imgchr.com/i/DKEDNn)
挑选一个合适的路径打开“Git Bash”，输入指令，将远程仓库克隆到本地：
```
git clone git@github.com:Krstar233/MyProject.git
```
期间会配对RSA key并询问你是否继续连接，直接输入“yes”继续克隆远程仓库。
[![DKZkz6.png](https://s3.ax1x.com/2020/11/19/DKZkz6.png)](https://imgchr.com/i/DKZkz6)
成功克隆远程仓库“MyProject”截图：
[![DKZjfI.png](https://s3.ax1x.com/2020/11/19/DKZjfI.png)](https://imgchr.com/i/DKZjfI)

### 安装和使用vscode
- 安装
在官网下载最新版本的安装包，打开之后按照常规的安装步骤即可。
在附加任务中可以自选一些选项：
[![DuXTUg.png](https://s3.ax1x.com/2020/11/19/DuXTUg.png)](https://imgchr.com/i/DuXTUg)

### 使用vscode协作git管理项目
- 打开项目文件
在vscode中，选择菜单栏中的“File”->“open Folder”,在文件管理器中找到并打开本地仓库“MyProject”。
[![DKm7IH.png](https://s3.ax1x.com/2020/11/19/DKm7IH.png)](https://imgchr.com/i/DKm7IH)
- 尝试修改README文件
输入markdown语句，修改README文件，同时点击vscode右上角的“Open Preview to the Side”图标，可以实时预览markdown效果。
    ```
    # MyProject
    # 一级标题
    ## 二级标题
    ### 三级标题
    - 项目1
    - 项目2
    - 项目3

    [测试链接](https://www.baidu.com)
    ```
    [![DK3MBq.png](https://s3.ax1x.com/2020/11/19/DK3MBq.png)](https://imgchr.com/i/DK3MBq)
    
- 相关插件安装
    - Markdown Preview Enhanced
    这个插件可以更好地查看markdown文件，有需要的可以在右侧栏选择“Extensions”图标，在输入框中进行搜索并安装。

- 更新内容到远程仓库
    Ctrl+S保存文件之后，在右侧栏的“Git”图标出现了提示，点击打开，在展开操作栏顶上的文本框中输入本次更新的信息
    [![DKQ1AO.png](https://s3.ax1x.com/2020/11/19/DKQ1AO.png)](https://imgchr.com/i/DKQ1AO)
    然后按下Ctrl+Enter进行commit操作，并在弹出的对话框中选择“Yes”或者“Always”。
    [![DKQdDP.png](https://s3.ax1x.com/2020/11/19/DKQdDP.png)](https://imgchr.com/i/DKQdDP)
    点击右侧栏的“Explorer”图标，在项目空白处右键选择“Open in Integrated Terminal”，然后我们可以在软件界面底部看见弹出的终端，并默认指向项目文件的路径。
    [![DK3tgJ.png](https://s3.ax1x.com/2020/11/19/DK3tgJ.png)](https://imgchr.com/i/DK3tgJ)
    输入指令，把本地仓库的新内容推送到远程仓库
    ```
    git push
    ```
    [![DK1tmt.png](https://s3.ax1x.com/2020/11/19/DK1tmt.png)](https://imgchr.com/i/DK1tmt)

    在Github上打开该远程仓库，发现文档内容得到了更新：
    [![DK3BE6.png](https://s3.ax1x.com/2020/11/19/DK3BE6.png)](https://imgchr.com/i/DK3BE6)

在团队协作中，如果别人更新了远程仓库的代码，那么在你本地仓库中的代码就不是最新版本了，这时候如果push到远程仓库会出现版本不一致不能push的情况。于是，我们需要输入“git pull”指令先将远程仓库拉取到本地进行更新。
- 从远程仓库更新内容到本地
    在GitHub上更改README文件的信息
    在仓库主页中点击readme预览页面上的“笔”图标：
    [![DKGftf.png](https://s3.ax1x.com/2020/11/19/DKGftf.png)](https://imgchr.com/i/DKGftf)
    修改文件，之后点击底部的“Commit changes”按钮进行更改：
    [![DKYZaq.png](https://s3.ax1x.com/2020/11/19/DKYZaq.png)](https://imgchr.com/i/DKYZaq)
    在vscode中，同样修改部分文件：
    [![DKYoes.png](https://s3.ax1x.com/2020/11/19/DKYoes.png)](https://imgchr.com/i/DKYoes)
    这时候，如果我们把本地仓库推送到远程是推送不了的：
    [![DKtSm9.png](https://s3.ax1x.com/2020/11/19/DKtSm9.png)](https://imgchr.com/i/DKtSm9)
    于是，我们输入“git pull”指令把远程仓库拉取到本地更新：
    [![DKtZOH.png](https://s3.ax1x.com/2020/11/19/DKtZOH.png)](https://imgchr.com/i/DKtZOH)
    这时候，我们发现，在编辑框中出现了异动，提示我们哪里进行了更新，同时因为部分代码段不一致导致的冲突，我们需要选择一种方式保存本地代码：
    [![DKt81S.png](https://s3.ax1x.com/2020/11/19/DKt81S.png)](https://imgchr.com/i/DKt81S)
    这里我选择接受拉取的代码，也就是“Accept Incoming Change”。最后，README文档的内容：
    [![DKtDpT.png](https://s3.ax1x.com/2020/11/19/DKtDpT.png)](https://imgchr.com/i/DKtDpT)

至此，使用vscode协作git管理项目的基本流程也就告一段落了。

## 相关资料
- [Git 教程 | 菜鸟教程](https://www.runoob.com/git/git-tutorial.html)
- [Markdown 教程 | 菜鸟教程](https://www.runoob.com/markdown/md-tutorial.html)