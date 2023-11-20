# GOOGLETEST AS GIt SUBMODULE

## CONFIG

Here, we will allow the `git` to include the `googletest` as a submodule by
its own, and will be installed directly using CMakeLists.txt

## SETUP AND PREPARATION

1. Get the `googletest` from github using the `submodule`
- Inside the `dependencies` directory.

```sh
git submodule add git@github.com:google/googletest.git
```
- You can get the inforamtion of the `googletest` using:

```sh
git submodule
```
- You can also update the `googletest` submodule easily using:

```git
git submodule update --init --recursive
```

2. We can automate this easily using the `cmake`, by adding the following script to the `dependencies/CMakeLists.txt`

