struct timer {
	decltype(chrono::high_resolution_clock::now()) begin;
	void start() {
		begin = chrono::high_resolution_clock::now();
	}
	void end() {
		auto end = chrono::high_resolution_clock::now();
		auto duration = chrono::duration_cast<chrono::milliseconds>(end - begin).count();
		cerr << duration << "ms elapsed" << endl;
	}
};
