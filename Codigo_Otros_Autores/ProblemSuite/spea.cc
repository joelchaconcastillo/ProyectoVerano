/*===========================================================================*/
/* SPEA: Strength Pareto Evolutionary Algorithm (SPEA)                       */
/*       program skeleton                                                    */
/*---------------------------------------------------------------------------*/
/* Explanations concerning the subroutines used:                             */
/*                                                                           */
/* pind  GetInd(ppop  pop, int  index):                                      */
/*   returns the individual with number 'index' of population 'pop'          */
/* void  SetInd(ppop  pop, int  index, pind  ind):                           */
/*   sets the individual 'ind' to be the member of population 'pop' with     */
/*   number 'index' (the first index is 0)                                   */
/* pind  CopyInd(pind  ind):                                                 */
/*   returns a copy of the individual 'ind'                                  */
/* void  SetFit(pind  ind, double  fitness):                                 */
/*   set the fitness value of individual 'ind' to 'fitness'                  */
/* double  GetFit(pind  ind):                                                */
/*   returns the fitness value of individual 'ind'                           */
/* void  FreeInd(pind  ind):                                                 */
/*   deallocates the memory used by the individual 'ind'                     */
/* int  GetSize(ppop  pop):                                                  */
/*   returns the size of the population 'pop'                                */
/* int  GetPopsize(void):                                                    */
/*   returns the fixed population size (set by the user)                     */
/* ppop  CreatePop(int  size):                                               */
/*   creates a population of size 'size'                                     */
/* int  irandom(int  n):                                                     */
/*   gives a random integer in the interval [0,n-1]                          */
/*                                                                           */
/* Data types:                                                               */
/*                                                                           */
/* pind:  pointer to an individual                                           */
/* ppop:  pointer to a population                                            */
/*---------------------------------------------------------------------------*/
/* Author: Eckart Zitzler                                                    */
/* (c)1998/1999 ETH Zurich, Switzerland                                      */
/*===========================================================================*/

#define FALSE  0
#define TRUE   1

#define MAX_NONDOMINATED_SOLUTIONS  1000

ppop   nondominatedSet;     /* external nondominated set                     */
int    noNondominated;      /* size of the external nondominated set         */
int    maxNondominated;     /* maximum size of external nondominated set     */
int*   clusters;            /* needed for clustering                         */
int*   clusterList;         /* needed for clustering                         */
int*   selectedSolutions;   /* needed for clustering                         */


int  dominatesOrEqual(pind  ind1, pind  ind2)
{
  /* returns TRUE iff ind1 dominates ind2 or both individuals have identical */
  /* objective values; otherwise, FALSE is returned                          */
} /* dominatesOrEqual */


void  markNondominatedIndividuals(ppop  pop)
  /* marks all nondominated individuals according to the population with     */
  /* fitness 0 */
{
  pind  indI, indJ;
  int   i, j;

  for (i = GetSize(pop) - 1; i >= 0; i--)
    SetFit(GetInd(pop, i), 0);
  for (i = GetSize(pop) - 1; i >= 0; i--) {
    indI = GetInd(pop, i);
    for (j = i - 1; j >= 0; j--) {
      indJ = GetInd(pop, j);
      if (GetFit(indJ) == 0)
	if (dominatesOrEqual(indI, indJ))
	  SetFit(indJ, 1);
	else if (dominatesOrEqual(indJ, indI)) {
	  SetFit(indI, 1);
	  /* individual IndI has not to be considered anymore as             */
	  /* nondominated                                                    */
	  break;
	}
    }
  }
} /* markNondominatedIndividuals */


void  updateExternalNondominatedSet(ppop  pop)
{
  pind  ind, nondomInd;
  int   i, j;
  int   dominated;

  for (i = GetSize(pop) - 1; i >= 0; i--) {
    ind = GetInd(pop, i);
    if (GetFit(ind) == 0) {
      dominated = FALSE;
      for (j = 0; j < noNondominated; j++) {
	nondomInd = GetInd(nondominatedSet, j);
	if (dominatesOrEqual(nondomInd, ind)) {
	  /* candidate is dominated by a solution in nondominatedSet */
	  dominated = TRUE;
	  break;
	}
	else if (dominatesOrEqual(ind, nondomInd)) {
	  /* candidate dominates a solution in nondominatedSet */
	  FreeInd(nondomInd);
	  SetInd(nondominatedSet, j, CopyInd(ind));
	  SetFit(GetInd(nondominatedSet, j), 0);
	  break;
	}
      }
      if (dominated == FALSE)
	if (j < noNondominated) {
	  /* remove all former pareto points dominated by the candidate */
	  j++;  /* next position because ind is stored at position j */
	  while (j < noNondominated) {
	    nondomInd = GetInd(nondominatedSet, j);
	    if (dominatesOrEqual(ind, nondomInd)) {
	      noNondominated--;
	      SetInd(nondominatedSet, j,
		     GetInd(nondominatedSet, noNondominated));
	      FreeInd(nondomInd);
	    }
	    else  j++;
	  }
	}
	else if (j == noNondominated) {
	  /* candidate is a new solution in nondominatedSet */
	  SetInd(nondominatedSet, j, CopyInd(ind));
	  SetFit(GetInd(nondominatedSet, j), 0);
	  noNondominated++;
	}
    }
  }
} /* updateExternalNondominatedSet */


double  IndDistance(pind  ind1, pind  ind2)
  /* phenotypic distance on objective values */
{
  /* return distance between the two individuals; note that scaling might be */
  /* be necessary                                                            */
  /*                                                                         */
  /* Example for two objectives:                                             */
  /*                                                                         */
  /*   distance = sqrt(                                                      */
  /*                (pow(f1(ind1) - f1(ind2), 2) /                           */
  /*                 pow(f1_max_value - f1_min_value, 2)) +                  */
  /*                (pow(f2(ind1) - f2(ind2), 2) /                           */
  /*                 pow(f2_max_value - f2_min_value, 2))                    */
  /*              )                                                          */
} /* IndDistance */


double  ClusterDistance(int  cluster1, int  cluster2)
{
  double  sum = 0;
  int  numOfPairs = 0;
  int  c1 = clusters[cluster1];
  while (c1 >= 0) {
    int  c2 = clusters[cluster2];
    while (c2 >= 0) {
      sum += IndDistance(GetInd(nondominatedSet, c1),
			 GetInd(nondominatedSet, c2));
      numOfPairs++;
      c2 = clusterList[c2];
    }
    c1 = clusterList[c1];
  }
  return (sum / double(numOfPairs));
} /* ClusterDistance */


void  JoinClusters(int  cluster1, int  cluster2, int&  numOfClusters)
{
  int  c1 = clusters[cluster1];
  while (clusterList[c1] >= 0)
    c1 = clusterList[c1];
  clusterList[c1] = clusters[cluster2];
  numOfClusters--;
  clusters[cluster2] = clusters[numOfClusters];
} /* JoinClusters */

 
int  ClusterCentroid(int  cluster)
{
  double  minSum = -1;
  int  minIndex;
  int  c1 = clusters[cluster];
  while (c1 >= 0) {
    int  c2 = clusters[cluster];
    double  sum = 0;
    while (c2 >= 0) {
      sum += IndDistance(GetInd(nondominatedSet, c1), GetInd(nondominatedSet, c2));
      c2 = clusterList[c2];
    }
    if (sum < minSum || minSum < 0) {
      minSum = sum;
      minIndex = c1;
    }
    c1 = clusterList[c1];
  }
  return minIndex;
} /* ClusterCentroid */


void  reduceNondominatedSet(void)
{
  /* firstly, define one-element-clusters */
  int  numOfClusters = noNondominated;
  for (int  i = 0 ; i < noNondominated; i++) {
    clusters[i] = i;
    clusterList[i] = -1;
  }
  /* join clusters using average linkage method */
  while (numOfClusters > maxNondominated) {
    /* find cluster pair with minimal distance */
    double  minDist = -1;
    int     join1, join2;
    for (int  c = 0; c < numOfClusters; c++) {
      for (int  d = c + 1; d < numOfClusters; d++) {
	double  dist = ClusterDistance(c, d);
	if (dist < minDist || minDist < 0) {
	  minDist = dist;
	  join1 = c;
	  join2 = d;
	}
      }
    }
    /* join cluster pair */
    JoinClusters(join1, join2, numOfClusters);
  }
  /* chose for each cluster representative solution (centroid) */
  for (i = 0; i < noNondominated; i++)
    selectedSolutions[i] = FALSE;
  for (i = 0; i < numOfClusters; i++)
    selectedSolutions[ClusterCentroid(i)] = TRUE;
  int  counter = 0;
  for (i = 0; i < noNondominated; i++) {
    if (selectedSolutions[i]) {
      if (counter != i) {
	SetInd(nondominatedSet, counter, GetInd(nondominatedSet, i));
      	SetInd(nondominatedSet, i, NULL);
      }
      counter++;
    }
    else {
      FreeInd(GetInd(nondominatedSet, i));
      SetInd(nondominatedSet, i, NULL);
    }
  }
  noNondominated = counter;
} /* reduceNondominatedSet*/


void  calcStrengths(ppop  pop)
{
  pind  ind, nondomInd;
  int   i, j;
  int   domCount;
  
  for (i = noNondominated - 1; i >= 0; i--) {
    nondomInd = GetInd(nondominatedSet, i);
    domCount = 0;
    for (j = GetSize(pop) - 1; j >= 0; j--)
      if (dominatesOrEqual(nondomInd, GetInd(pop, j)))
	domCount++;
    SetFit(nondomInd, double(domCount) / double(GetSize(pop) + 1));
  }
} /* calcStrengths */


void  calcFitness(ppop  pop)
{
  pind    ind, nondomInd;
  int     i, j;
  double  fitness;

  for (i = GetSize(pop) - 1; i >= 0; i--) {
    ind = GetInd(pop, i);
    fitness = 0.0;
    for (j = noNondominated - 1; j >= 0; j--) {
      nondomInd = GetInd(nondominatedSet, j);
      if (dominatesOrEqual(nondomInd, ind))
	fitness += GetFit(nondomInd);
    }
    SetFit(ind, 1.0 + fitness);
  }
} /* calcFitness */


void  SPEA(ppop  pop)
  /* fitness assignment */
{
  markNondominatedIndividuals(pop);
  updateExternalNondominatedSet(pop);
  if (noNondominated > maxNondominated)
    reduceNondominatedSet();
  calcStrengths(pop);
  calcFitness(pop);
} /* SPEA */


void  binaryTournamentSelection(ppop  *pop)
{
  int  size = GetSize(*pop);
  ppop  newPop = CreatePop(size);
  for (int  i = 0; i < size; i++) {
    pind  a,b;
    int  n = irandom(size + noNondominated);
    if (n < size)  a = GetInd(*pop, n);
    else           a = GetInd(nondominatedSet, n - size);
    n = irandom(size + noNondominated);
    if (n < size)  b = GetInd(*pop, n);
    else           b = GetInd(nondominatedSet, n - size);
    if (GetFit(a) > GetFit(b))
      SetInd(newPop, i, CopyInd(b));
    else
      SetInd(newPop, i, CopyInd(a));
  }
  FreePop(*pop);
  *pop =  newPop
} /* binaryTournamentSelection */


void  main()
{
 noNondominated = 0;
 maxNondominated = MAX_NONDOMINATED_SOLUTIONS;
 int  nondominatedSetUpperBound = GetPopsize() + maxNondominated;
 clusters = (int *) calloc(nondominatedSetUpperBound, sizeof(int));
 clusterList = (int *) calloc(nondominatedSetUpperBound, sizeof(int));
 selectedSolutions = (int *) calloc(nondominatedSetUpperBound, sizeof(int));
 nondominatedSet = CreatePop(nondominatedSetUpperBound);
 ppop  pop = CreatePop(GetPopsize());
 /* main loop */
 for (int  i = 0; i < maxGenerations; i++) {
   SPEA(pop);
   binaryTournamentSelection(&pop);
   crossover(pop);
   mutation(pop);
 }
} /* main */
