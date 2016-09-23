#include <utility/ostream.h>
#include <thread.h>

using namespace EPOS;

OStream cout;

void foo(Thread& bar) {
	cout << "Locking " << bar << endl;
	bar->join();
}

int main() {
	Thread * a[3];
	a[0] = new Thread(&foo, a[1]);
	a[1] = new Thread(&foo, a[2]);
	a[2] = new Thread(&foo, a[0]);

	a[0]->join();
	cout << "Done" << endl;

	return 0;
}
