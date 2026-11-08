# Keeping this fork in sync

The original repository is `https://github.com/deathkiller/jazz2-native`, branch
`master`. Keep its commits in the fork's history by merging them; avoid rebasing
or force-pushing the published `master` branch.

From a clean checkout on `master`, run this regularly (ideally before starting
new changes, and at least weekly):

```powershell
./tools/Sync-Upstream.ps1
# Review the merge and run the relevant builds/tests, then:
git push origin master
```

The script first fast-forwards from the fork, fetches upstream without importing
its tags, then merges it. It enables Git's local `rerere` cache so previously
reviewed conflict resolutions can be reused. Reused resolutions are not staged
automatically: inspect them before committing. A conflict stops the script;
resolve it, stage the affected files and run `git commit`. To cancel an unfinished
merge, use `git merge --abort`. The optional `-Push` switch pushes after a clean
merge; it does not run build checks.

The **Upstream merge check** action checks mergeability daily, on pushes and on
pull requests. It does not modify branches. A failed run makes a new conflict
visible early; it does not establish that a clean merge compiles or works.
Scheduled runs depend on GitHub Actions being enabled for the workflow in this
fork. The workflow can also be started manually.

Keep fork-specific automation in separate files. Leave upstream platform
workflows intact and disable unwanted workflows in this fork's Actions settings.
For game changes, follow upstream naming conventions and keep edits small and
focused. These practices reduce conflicts, but changes to the same code on both
sides will still sometimes require manual resolution.
