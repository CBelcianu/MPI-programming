#include <iostream>
#include <vector>
#include "mpi.h"

using namespace std;

inline void send_work_naive(vector <int>& a, vector <int>& b, int nrProcs) {
	int n = a.size();
	for (int i = 1; i < nrProcs; ++i) {
		MPI_Send(&n, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
		MPI_Send(a.data(), n, MPI_INT, i, 1, MPI_COMM_WORLD);
		MPI_Send(b.data(), n, MPI_INT, i, 2, MPI_COMM_WORLD);
	}
	cout << "master sent work\n";
}

inline void collect_naive(int nrProcs, vector <int>& res) {
	int l = res.size();
	for (int i = 1; i < nrProcs; ++i) {
		MPI_Status _;
		MPI_Recv(res.data(), l, MPI_INT, i, 3, MPI_COMM_WORLD, &_);
	}
	cout << "master collected the results\n";
}

inline void naive_multiply(vector<int> a, vector<int> b, vector<int> &prod, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			prod[i + j] += a[i] * b[j];
	}
}

inline void worker_naive(int me) {
	cout << "worker(" << me << ") started\n";
	int n;
	MPI_Status _;
	MPI_Recv(&n, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, &_);
	vector <int> a(n);
	vector <int> b(n);
	MPI_Recv(a.data(), n, MPI_INT, 0, 1, MPI_COMM_WORLD, &_);
	MPI_Recv(b.data(), n, MPI_INT, 0, 2, MPI_COMM_WORLD, &_);
	vector <int> res(2*n-1);
	naive_multiply(a, b, res, n);
	MPI_Send(res.data(), 2*n-1, MPI_INT, 0, 3, MPI_COMM_WORLD);
	cout << "worker(" << me << ") finished\n";
}

int main()
{
	MPI_Init(0, 0);
	int me;
	int nrProcs;
	MPI_Comm_size(MPI_COMM_WORLD, &nrProcs);
	MPI_Comm_rank(MPI_COMM_WORLD, &me);

	unsigned int n = 10;
	vector<int> a, b;
	a = { 1, 2, 3, 3, 6, 2, 7, 5, 9, 8 };
	b = { 2, 5, 3, 3, 7, 5, 8, 9, 3, 8 };

	if (me == 0) {
		send_work_naive(a, b, nrProcs);
		vector <int> res(2 * n - 1);
		collect_naive(nrProcs, res);
		for (int i = 0; i < res.size(); i++) {
			cout << res[i] << ' ';
		}
	}
	else {
		worker_naive(me);
	}
	MPI_Finalize();
}