git init
set /p name="你的文件名"
set /p branch="上传到的文件夹"
set /p message="输入你提交的注释"
git add %name%
git commit -m "%message%"
git push git@github.com:doorOfChoice/%branch%.git master
pause