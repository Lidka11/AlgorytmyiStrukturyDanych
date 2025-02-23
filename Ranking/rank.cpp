
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool sortbysec(const pair < int, int > & a,
  const pair < int, int > & b) {
  return (a.second < b.second);
}

int main() {

  int n; // number of participants
  cin >> n;
  int points;

  vector < pair < int, int > > v;
  for (int i = 0; i < n; i++) {
    cin >> points;
    v.push_back(make_pair(points, i + 1));
  }

  //sort of vector
  sort(v.begin(), v.end());

  vector < pair < int, int > > ::reverse_iterator rv = v.rbegin();

  int currentPoints = -1;
  int currentRank = 1;

  pair < int, int > tmp; //auxiliary pair

  int lastCompetitor;

  for (rv = v.rbegin(); rv != v.rend(); ++rv) {

    if (currentRank == 1) {
      tmp = * rv;
      currentPoints = tmp.first;
      tmp.first = 1;
      * rv = tmp;
      lastCompetitor = tmp.first;
      currentRank++;
    } else { //draws
      tmp = * rv;
      if (currentPoints == tmp.first) {
        currentPoints = tmp.first;
        tmp.first = lastCompetitor;
      } else {
        currentPoints = tmp.first;
        tmp.first = currentRank;

      }
      lastCompetitor = tmp.first;

      * rv = tmp;
      currentRank++;

    }

  }
  sort(v.begin(), v.end(), sortbysec);
  cout << endl;
  for (int i = 0; i < n; i++) {
    cout << v[i].first << " "; //displaying the ranking
  }

}
