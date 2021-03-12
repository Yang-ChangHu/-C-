#include"TopoLogical.h"

bool TopoLogical::isCycle()
{
	return order.isEmpty();
}
stack<int> TopoLogical::Order()
{
	return this->order;
}
TopoLogical::TopoLogical(class Digraph G)
{
	Digraph nG=G;
	DirectedCycle dc(nG);
	if (!dc.hasCycle())
	{
		DepthOrder DO(G);
		DO.ReversePost().showMessage();
		/*this->order=DO.ReversePost();
		order.showMessage();*/
	}
	else
	{
		cout << "ÓÐ»·" << endl;
	}

}