#include <gvc.h>

void test1()
{

	GVC_t *gvc;
    gvc = gvContext();

	g = agopen("g", AGDIGRAPH);
	gvRender(gvc, g, "dot", stdout);

}

int main()
{

	test1();
	return 0;
}