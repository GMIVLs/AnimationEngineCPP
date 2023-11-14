# Git and Git-Workflow

## Daily Commands

| idx   | commadn                    | branch execute command | Note                                              |
| ----- | ---------                  | --------               | ------                                            |
| 1     | git checkout main          | feature/dev/M          | We go to bring the newest update from main branch |
| 2     | git fetch && git rebase    | main                   | go bring form remote branch the latest upadates   |
| 3     | git checkout feature/dev/M | main                   | we go now back to our branch                      |
| 4     | git rebase main            | feature/dev/M          | Now, we rebasing all the work on top of our work  |

- Here, we can add more details for all the changes in the future work.

```sh
Assume you are at your branch (feature/dev/M) -> git checkout main
Now you are on main branch -> git fetch && git rebase
git checkout feature/dev/M
git rebase main
```

## WORK FLOW - DAILY ACTIVITIES

`git pull` and `git fetch` followed by `git rebase` are two ways to update your
local repository with changes from a remote repository. Here's a simple
explanation of both:

- **git pull:** This command fetches the changes from the remote repository to
  your current branch and immediately tries to merge them into your branch. It's
  a combination of `git fetch` followed by `git merge`. If you're on a branch and
  you execute `git pull`, Git will automatically fetch the changes for that
  branch from the remote and then merge them into your local copy of the branch.

- **git fetch followed by git rebase:** `git fetch` updates your remote
  tracking branches but does not change any of your own local branches; it
  fetches the remote content but doesn't integrate it into your work. `git
rebase` is then used to reapply your local changes on top of the fetched
  changes. The advantage of using `git rebase` over `git merge` (which is what
  `git pull` does) is that `git rebase` will create a cleaner, linear history
  without merge commits.

Regarding the optimal workflow for a developer working on a shared project,
here's a common approach:

1. **Create a Branch for Each New Task:** Yes, you should create a new branch
   for each task or feature you work on. This isolates your changes and makes
   it easier to manage merges and review history.

2. **Update Your Branch Daily:** To keep your branch up-to-date with the main
   branch (often called `master` or `main`), you should regularly update it,
   especially before you start working for the day, and before you push any
   changes. You can do this by fetching the latest changes from the main branch
   and then rebasing your branch on top of it:

```sh
git checkout main
git pull origin main
git checkout your-feature-branch
git rebase main
```

If you encounter any conflicts during the rebase, Git will stop and allow you
to resolve them. After resolving conflicts, continue the rebase with `git
rebase --continue` until all changes are applied.

3. **How Other Developers Use Your Branch:**
   If your branch is pushed to the remote repository, other developers can check
   out your branch to work on it or review it by doing:

```sh
git fetch origin
git checkout -b your-feature-branch origin/your-feature-branch
```

They can then make changes and push them back to the remote branch, which you
can fetch and rebase onto your local branch as needed.

4. **Merging with the Main Branch:** Once your task is completed, and you have
   an up-to-date branch with the latest changes from the main branch (after a
   rebase), you should push your branch and open a pull request (PR) or merge
   request (MR) in your repository hosting service (like GitHub, GitLab,
   Bitbucket, etc.). Your team can then review the changes. After approval, your
   branch can be merged into the main branch.

5. **Resolve Any Conflicts:** If there are conflicts between your branch and
   the main branch when you try to merge, you will need to resolve these
   conflicts. Sometimes, you can resolve conflicts directly on the PR/MR
   interface; other times, you may need to pull the changes, resolve conflicts
   locally, and then push the resolved branch.

6. **Delete Your Branch After Merge:** After your branch has been merged, it's
   usually safe to delete your local and remote branches to keep the repository
   clean.

This workflow helps to maintain a clean and navigable project history, allows
for easy code review, and reduces the chance of complicated merge conflicts. It
also ensures that features are developed in manageable, isolated chunks.

```
+----------------------+           +------------------------+
|  Create a new branch |           | Work on your feature or |
|  for each new task   |           | task in this branch     |
+----------------------+           +------------------------+
         |                                    |
         |                                    |
         |---+                                |
         |                                    |
         v                                    v
+----------------------+          +-------------------------+
| Update branch daily  |          | Other developers work on|
| with the main branch |          | the main branch or other|
| changes:             |          | feature branches        |
| git fetch &&         |          |                         |
| git rebase           |          +-------------------------+
+----------------------+                     |
         |                                   |
         |                                   |
         v                                   v
+----------------------+          +-------------------------+
| Resolve any conflicts|          | They fetch changes from |
| that arise during    |          | the main branch and      |
| rebase               |          | rebase as necessary     |
+----------------------+          +-------------------------+
         |                                    |
         |                                    |
         v                                    v
+----------------------+          +-------------------------+
| Push the updated     |          | Once your feature is    |
| feature branch to    |          | complete and up-to-date,|
| remote               |          | push to remote and open |
+----------------------+          | a pull request          |
         |                        +-------------------------+
         |                                    |
         |<-----------------------------------+
         |
         v
+----------------------+
| Review, then merge   |
| feature branch into  |
| the main branch      |
+----------------------+
         |
         |
         v
+----------------------+
| Delete the feature   |
| branch after merge   |
+----------------------+

```


## References
