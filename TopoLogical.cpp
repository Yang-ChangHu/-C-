#include"TopoLogical.h"

bool TopoLogical::isCycle()
{
	return order.isEmpty();
}
stack<int> TopoLogical::Order()
{
	return this->order;
}
TopoLogical::TopoLogical(const class Digraph& G)
{
	DirectedCycle dc(G);

	if (!dc.hasCycle())
	{
		DepthOrder DO(G);
		DO.ReversePost().showMessage();

	}
	else
	{
		cout << "ÓÐ»·" << endl;
	}

}