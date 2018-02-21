//
// Created by Thomas Couchoud on 06/02/2018.
//

#include "SortPat.h"
#include "vector"

using namespace std;

SortPat::SortPat() = default;

Patient & SortPat::operator()(Patient & p)
{
	sort(p.getRessources().begin(), p.getRessources().end());
	return p;
}
