cd $1
git commit -m "$2"
mv .git/ .git_unloaded/
cd ..
git add $1/
git commit -m "$1/$2"
cd $1
mv .git_unloaded/ .git/
cd ..
