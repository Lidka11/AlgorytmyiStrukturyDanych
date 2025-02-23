
#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

// data
int cc; // number of components
int N; // number of elements
vector < int > id; // id[i] = parent of i
vector < int > sz; // sz[i] = number of elements in subtree rooted at i

// initializes data structures
void init(int size) {
  cc = size;
  N = size;

  id.resize(size);
  sz.resize(size);

  for (int i = 0; i < N; i++) {
    id[i] = i;
    sz[i] = 1;
  }
}

// gets component's identifier of the element
int find(int p) {
  int r = p;

  while (r != id[r]) // find
  {
    r = id[r];
  }

  while (p != r) // path compression
  {
    int n = id[p];
    id[p] = r;
    p = n;
  }

  return r;
}

// check if 2 elements belongs to the same component
bool connected(int p, int q) {
  return find(p) == find(q);
}

// connect components
void make_union(int p, int q) {
  int pid = find(p);
  int qid = find(q);

  if (pid == qid) return;

  // make smaller root point to larger one
  if (sz[qid] < sz[pid]) {
    id[qid] = pid;
    sz[pid] += sz[qid];
  } else {
    id[pid] = qid;
    sz[qid] += sz[pid];
  }

  cc--;
}

int main() {
  int n; //enters the size of the array
  cin >> n;
  init(n * n);

  // enters map of sky
  vector < int > skymap(n * n);
  for (int i = 0; i < n * n; i++) {
    cin >> skymap[i];
  }

  //combines ones and zeros into constellations
  int no_zeros = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (skymap[i * n + j] == 1) {

        if (i > 0 && skymap[(i - 1) * n + j] == 1) {
          make_union(i * n + j, (i - 1) * n + j);
        }

        if (j > 0 && skymap[i * n + j - 1] == 1) {
          make_union(i * n + j, i * n + j - 1);
        }
      } else {
        sz[i * n + j] = 0;
        no_zeros++;
      }
    }
  }

  //looks for the biggest constellation
  int max_constellation = 0;
  for (const int & s: sz) {
    if (s > max_constellation) max_constellation = s;
  }

  int nr_constellations = cc - no_zeros;

  //prints the result
  cout << nr_constellations << " " << max_constellation;

}
