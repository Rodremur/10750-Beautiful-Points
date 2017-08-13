/*-------------------------------------------------------
 * Tarea de Analisis de Algoritmos: 10750 - Beautiful Points
 * Fecha: 02-03-2016
 * Autor:
 *      A01064215 Rodrigo Reyes Murillo
 * Referencia: PChome(12/7/2013). http://mypaper.pchome.com.tw/zerojudge/post/1324860219
 */

#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

struct Point
{
	int x;
	int y;

	bool operator<(const Point &source) const {
        if (x != source.x) {
            return x < source.x;
        }
        return y < source.y;
	}
};

Point pts[10000];
double pointx, pointy;
int mindis;

int distancex(int a, int m) {
    return (pts[a].x - pts[m].x)*(pts[a].x - pts[m].x);
}
int distancey(int a, int m) {
    return (pts[a].y - pts[m].y)*(pts[a].y - pts[m].y);
}

void closestPair(int low, int high) {
    if (low >= high) return;
    int i, j, mid;

    mid = (low + high) /2;
    closestPair(low, mid);
    closestPair(mid+1, high);

    for (i = mid; i >= low; i--) {
        if (distancex(i, mid) >= mindis) break;
        for (j = mid+1; j <= high; j++) {
            if (distancex(i, j) >= mindis) {
                break;
            }
            int v = distancex(i, j) + distancey(i, j);
            if (v < mindis) {
                mindis = v;
                pointx = (pts[i].x+pts[j].x)/2.0;
                pointy = (pts[i].y+pts[j].y)/2.0;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
	int cases, i, j, k, n;

    scanf("%d", &cases);
    for (k = 0; k < cases; k++) {
    	scanf("%d", &n);
    	for (j = 0; j < n; j++) {
    		scanf("%d %d", &pts[j].x, &pts[j].y);
    	}
        sort(pts, pts+n);
        mindis = pow(2, 16) -1;
        closestPair(0, n-1);
    	printf("%.3f %.3f\n", pointx, pointy);
    }
}
