## Assignment 2 ->

#### OpenMP -> spmd

- Work-sharing constructs can be used to divide a task among the threads so that each thread executes its allocated part of the code. Both task parallelism and data parallelism can be achieved using OpenMP in this way.

#### Work-sharing constructs ->

- A worksharing construct distributes the execution of the corresponding region among the members of the team that encounters it. Threads execute portions of the region in the context of the implicit tasks that each one is executing.

1. Implicit barrier at the end of **For** work-sharing construct and at the end of parallel region
2. No impicit barrier due to **Nowait**
3. Private: Declares the scope of the data variables in list to be private to each thread. Data variables in list are separated by commas.
4. Firstprivate: Declares the scope of the data variables in list to be private to each thread. Each new private object is initialized as if there was an implied declaration within the statement block. Data variables in list are separated by commas.
5. Lastprivate: Declares the scope of the data variables in list to be private to each thread. The final value of each variable in list, if assigned, will be the value assigned to that variable in the last iteration. Variables not assigned a value will have an indeterminate value. Data variables in list are separated by commas.
6. Shared: A variable in an OpenMP parallel region can be either shared or private. If a variable is shared, then there exists one instance of this variable which is shared among all threads.
7. Schedule: a specification of how iterations of associated loops are divided into contiguous. non-empty subsets.
8. Reduction: Performs a reduction on all scalar variables in list using the specified operator. Reduction variables in list are separated by commas. A private copy of each variable in list is created for each thread. At the end of the statement block, the final values of all private copies of the reduction variable are combined in a manner appropriate to the operator, and the result is placed back in the original value of the shared reduction variable.
9. Barrier: Each thread waits until all the threads have arrived
