# Deep error: using ios::sync_with_stdio(false) may cause unknown error.
There is the same problem in 1114 1126;
In general, using printf and cout in the same time could cause the problem.
In addition, 1143 using this declaration could solve the <em>timeout</em> problem!

# various function
### count_if(iterator 1,iterator 2,cmp) 
accurate the number that satisfied the conditions;
### find(iterator 1,iterator 2,cmp) 
return relative iterator.
### iota(int *a,int *a+a.length,0) 
the function makes an array ,the value equals to the index
1114 use iota function 
### equal(a.begin(),a.end(),s.begin(),s.end())
the function can check that if a equals to s;

### copy_n()
***

## union find set
1118 union find set problem. watch out that sometimes compressing the paths is necessary
1158 unuion and set must be solved by the thought.
***

## different type calculator
character + number = <font color="#dd0000">ASCLL</font> number;
number + character = <font color="#dd0000">ASCLL</font> number;
  
***
##### judge if a graph is connected can use DFS or union set..

##### red-black tree , the third rule nil node is the child node of leaf node.

## initialize judging conditions(1076)
Like DFS,Dijkkstra,BFS algorithm, it may be better to set initial value in the customized function instead of in the main function.
But it could cause another problem that returning the indicated value could be more complex(Dijkstra).

## lambda function(annoymous)
This feature is really useful。
Here is the normal structure
```
// watch out: the type of lambda must be auto.
auto lambda=[&a](int parameter) ->int {
 return 1
};
lambda();
[ ] can catch variable. There are two character to modify the operation-- '=' || '&'
```
## About Debug skill
try to use '\n' rather than endl
``` typeid(variable name).name() ``` could help you get the right type
try to use PTA test demo. And remember that the answer would judge the "\n".