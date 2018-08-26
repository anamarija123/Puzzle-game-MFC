#include "stdafx.h"
#include "PointOperators.h"

bool operator==(POINT a, POINT b) { return a.x == b.x && a.y == b.y; }
