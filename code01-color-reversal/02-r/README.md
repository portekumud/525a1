This directory contains implementation of local complementation.



# 1. Prerequisite

Execute the following command to enter into a proper environment.

```shell
source env01-kumud-localComplementation/bin/activate
```

Once the mentioned environment is activated, we can proceed for the following.

# 2. List of directories

The following directories are present.

-   01-lcOnAsingleVertex/
-   02-lcOnAsequenceOfVertices/
-   03-lcOnAsequenceOfLexicographicallySortedVertices/


## 2.1 Inside directory 01-lcOnAsingleVertex/

Execute the following code  to change the _present working directory_ as _01-lcOnAsingleVertex_.

```shell
cd 01-lcOnAsingleVertex/
```

Then type

```shell
make -s
```
to run the code inside directory `01-lcOnAsingleVertex/`. Once successfully executed, it will create following two graphs:

-   the _initial graph_, and
-   the _graph_ after _local complementation_ on the _mentioned vertex_.

Now run the following command to view them:

```shell
evince graph01-initial.pdf && evince graph02-afterLocalCom.pdf
```
