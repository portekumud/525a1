This directory contains implementation of local complementation.


---

### Table of contents

1.	[Prerequisite](#s1)
    -   1.1 [Prerequisite for the first time execution](#s11)
    -   1.2 [Prerequisite for the second time onwards](#s12)
2.  [List of directories](#s2)
    -   2.1 [Applying `color reversal` at a single vertex](#s21)
    -   2.2 [Applying `color reversal` using a sequence of vertices](#s22)
    -   2.3 [Applying `color reversal` using lexicographically sorted strings](#s23)

---

# 1. Prerequisite <a name="s1"></a>

## 1.1 Prerequisite for the first time execution <a name="s11"></a>

1.  Execute the following command to create a _virtual environment_ for this experiment.

```shell
python3 -m venv env01-kumud-localComplementation
```

2.  Then execute the following command to enter into the _virtual environment_.

```shell
source env01-kumud-localComplementation/bin/activate
```

3.  Once the mentioned environment is activated, we run the following command to install some required packages:

```shell
bash script01-installPrerequisite.sh
```

4.  Done, please skip [subsection 1.2](#s12) and go to [section 2](#s2).

## 1.2 Prerequisite for the second time onwards <a name="s12"></a>


1.  Execute the following command to enter into the _virtual environment_.

```shell
source env01-kumud-localComplementation/bin/activate
```



# 2. List of directories <a name="s2"></a>

The following directories are present.

-   01-lcOnAsingleVertex/
-   02-lcOnAsequenceOfVertices/
-   03-lcOnAsequenceOfLexicographicallySortedVertices/


## 2.1 Applying `color reversal` at a single vertex <a name="s21"></a>

1.  Execute the following code  to change the _present working directory_ as _01-lcOnAsingleVertex_.

```shell
cd 01-lcOnAsingleVertex/
```

2.  Once we are inside the directory `01-lcOnAsingleVertex/`, we need to type

```shell
make clean
```

to remove the unnecessary files generated from the last execution.


3.  Now run the following code to do _local complementation_ at vertex _q_ of input graph _p_. Note that here _q_ is the _pivot vertex_. Here _pivot vertex_ means that specific vertex on which _local complementation_ is supposed to be performed. We need to provide an integer value in the place of _q_.

```shell
make kumud01 graph=../input/p vertex=q
```

For example, run `make kumud01 graph=../input/input3 vertex=4` to do _local complementation_ on the `4`th vertex of `input3` graph.
> [!CAUTION] 
> The value of _q_ must belong to the set of vertices; otherwise this implementation stops. 



4.  Once successfully executed, it will create following two graphs:

-   the _initial graph_, and
-   the _graph_ after _local complementation_ on the _mentioned vertex_.


5. The two graphs can be viewed accordingly. Altenatively, we can use the following command to view the two graphs:

```shell
bash script01-showOutput.sh
```

6.  We are done here.


## 2.2 Applying `color reversal` using a sequence of vertices <a name="s22"></a>

1. Execute the following command to change the _present working directory_ as `02-lcOnAsequenceOfVertices`.

```shell 
cd ../02-lcOnAsequenceOfVertices/` 
```

2. Then type the following command to run the implementation.

```shell
make -s kumud02 graph=../input/p sequence="v0 v1 v2 ... vn-1"
```

> [!NOTE]
> Here `p` is the input graph and `v0 v1 v2 ... vn-1` is a valid sequence of vertices.

For example, the following is one valid syntax:
```shell
make kumud02 graph=../input/input2 sequence="0 1 2"
```

This command will perform `local complementaion` on the `input2` graph using the sequence `0 1 2`.

Another example is the following command:
```shell
make kumud02 graph=../input/input5 sequence="0 1 0 2 0 2 1 2 1"
```
3. The results are available in the two files, `equalOrNot` and `theoutput`.

4. All output graphs are visible in the `.png` format.

5. Done.

## 2.3 Applying `color reversal` using lexicographically sorted strings <a name="s23"></a>


1. Execute the following command to change the _present working directory_ as `03-lcOnAsequenceOfLexicographicallySortedVertices`.

```shell 
cd ../03-lcOnAsequenceOfLexicographicallySortedVertices/
```

2. Then type the following command to run the implementation.

```shell
make -s kumud03 graph=../input/p lexicographyLimit=q
```

> [!NOTE]
> Here `p` is the input graph and `q` is the maximum length of the strings being generated lexicographically.

For example, the following is one valid syntax:
```shell
make -s kumud03 graph=../input/input4 lexicographyLimit=2
```
This command will generate all lexicographically strings upto length `2` using the alphabet set as the set of vertices of the graph. Then `color inversion` will be performed on those strings sequentially. 


Another example is the following command which will generate all strings in lexicographically order upto length 9 and `color inversion` is applied on all of them sequentially using the input5 graph.

```shell
make  kumud03 graph=../input/input5 lexicographyLimit=9
```

3. The resultant graphs are available in the <a href="allFilesPNG/"> allFilesPNG</a> directory.

4. The brief output is available in the <a href="output/"> output</a> directory.

5. A detailed log file is available in the <a href="log/"> log</a> directory.

6. Done.
