git add .
msg=20$(date +%y-%m-%d)
git commit -m "update : ${msg}"
git push mygithub master