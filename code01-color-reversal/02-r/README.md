This directory contains implementation of local complementation.

### Table of contents

1.	[Prerequisite](#s1)
    -   1.1 [Prerequisite for the first time execution](#s11)
    -   1.2 [Prerequisite for the second time onwards](#s12)
2.  [List of directories](#s2)
    -   2.1 [Inside directory 01-lcOnAsingleVertex/](#s21)
    -   2.2 [Inside directory 02-lcOnAsequenceOfVertices/](#s22)
    -   2.3 [Inside directory 03-lcOnAsequenceOfLexicographicallySortedVertices/](#s23)

---

# 1. Prerequisite <a name="s1"></a>

## 1.1 Prerequisite for the first time execution <a name="s11"></a>

Execute the following command to create a _virtual environment_ for this experiment.

```shell
python3 -m venv env01-kumud-localComplementation
```


Execute the following command to enter into the _virtual environment_.

```shell
source env01-kumud-localComplementation/bin/activate
```

Once the mentioned environment is activated, we run the following command to install some required packages:

```shell
bash script01-installPrerequisite.sh
```

Done. Please skip [subsection 1.2](#s12) and go to [section 2](#s2).

## 1.2 Prerequisite for the second time onwards <a name="s12"></a>

Execute the following command to enter into the _virtual environment_.

```shell
source env01-kumud-localComplementation/bin/activate
```



# 2. List of directories <a name="s2"></a>

The following directories are present.

-   01-lcOnAsingleVertex/
-   02-lcOnAsequenceOfVertices/
-   03-lcOnAsequenceOfLexicographicallySortedVertices/


## 2.1 Inside directory 01-lcOnAsingleVertex/ <a name="s21"></a>

Execute the following code  to change the _present working directory_ as _01-lcOnAsingleVertex_.

```shell
cd 01-lcOnAsingleVertex/
```

Then type

```shell
make clean
```

to remove the unnecessary files generated from the last execution.


Now run

```shell
make -s
```

to run the code inside directory `01-lcOnAsingleVertex/`. Once successfully executed, it will create following two graphs:

-   the _initial graph_, and
-   the _graph_ after _local complementation_ on the _mentioned vertex_.

and the two graphs are visible.




## 2.2 Inside directory 02-lcOnAsequenceOfVertices/<a name="s22"></a>


## 2.3 Inside directory 03-lcOnAsequenceOfLexicographicallySortedVertices/<a name="s23"></a>
