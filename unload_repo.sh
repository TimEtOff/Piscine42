echo ¨$1¨
if [ -d ¨/$1/.git¨]; then
    mv /$1/.git /$1/.git_unloaded
else
    mv /$1/.git_unloaded /$1/.git
fi
