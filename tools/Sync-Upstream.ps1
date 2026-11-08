param([switch]$Push)

$ErrorActionPreference = 'Stop'

function Invoke-Git {
    & git @args
    if ($LASTEXITCODE -ne 0) {
        throw "git $($args -join ' ') failed. Resolve any merge conflicts, review and commit before pushing."
    }
}

Push-Location (Split-Path $PSScriptRoot -Parent)
try {
    $branch = & git branch --show-current
    if ($LASTEXITCODE -ne 0 -or $branch -ne 'master') {
        throw 'Switch to master before syncing.'
    }
    $changes = & git status --porcelain
    if ($LASTEXITCODE -ne 0 -or $changes) {
        throw 'Commit or stash local changes (including untracked files) before syncing.'
    }

    # Keep previous resolutions available, but leave their staging to the reviewer.
    Invoke-Git config rerere.enabled true
    Invoke-Git config rerere.autoupdate false
    Invoke-Git fetch origin
    Invoke-Git merge --ff-only origin/master
    # Use a dedicated ref and no upstream tags: build-* tags belong to this fork.
    Invoke-Git fetch --no-tags https://github.com/deathkiller/jazz2-native.git '+refs/heads/master:refs/remotes/upstream/master'
    Invoke-Git merge --no-edit refs/remotes/upstream/master

    if ($Push) {
        Invoke-Git push origin master
    }
} finally {
    Pop-Location
}
