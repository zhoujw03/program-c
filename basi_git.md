##git里的一些基础指令
1. 配置与初始化

在开始之前，先告诉 Git 你是谁。

git config --global user.name "你的名字"：设置用户名。

git config --global user.email "你的邮箱"：设置邮箱。

git init：在当前文件夹初始化一个新的 Git 仓库。

git clone [url]：从远程服务器克隆一个现有的项目。

2. 基础操作（最常用）

这是你每天循环往复的操作流程：修改 -> 暂存 -> 提交。

git status：查看当前状态（哪些文件改了还没存）。

git add <文件名>：将特定文件添加到暂存区。

git add .：将所有修改过的文件一次性加入暂存区（最常用）。

git commit -m "提交说明"：将暂存区的内容正式保存到本地仓库。

3. 分支管理

分支让你可以在不影响主代码（main/master）的情况下实验新功能。

git branch：查看所有分支。

git checkout -b <分支名>：创建一个新分支并立即切换过去。

git checkout <分支名>：切换到已有分支。

git merge <分支名>：将指定分支的代码合并到当前分支。

4. 远程协作

把你的代码推向世界，或者同步伙伴的代码。

git remote add origin [url]：关联本地仓库与远程 GitHub 仓库（仅需做一次）。

git push -u origin <分支名>：将本地代码推送到远程仓库。

git pull：拉取远程仓库的最新改动并自动合并。

git fetch：只下载远程改动，但不自动合并（更安全）。

💡 一个典型的“搬砖”流程

如果你今天写了一段代码，打算上传到 GitHub，操作顺序通常是：

git add . （把代码塞进包里）

git commit -m "完成了登录页面功能" （贴上标签）

git pull （先看看别人有没有更新，防止冲突）

git push origin main （把包扔到服务器上）

进阶小贴士

git log：查看详细提交历史，看看大家都干了啥。

git log --oneline ：快速的查看过去的提交记录

git diff：查看具体的代码行改动。

git checkout -- <文件名>：后悔药！ 撤销还没提交的修改，回到文件最后一次提交的状态。