git init
set /p name="����ļ���"
set /p branch="�ϴ������ļ���"
set /p message="�������ύ��ע��"
git add %name%
git commit -m "%message%"
git push git@github.com:doorOfChoice/%branch%.git master
pause