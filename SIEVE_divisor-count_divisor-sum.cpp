//https://cp-algorithms.com/algebra/divisors.html

int sp[SZ];

void sieve() {
	for (int i = 2; i < SZ; i++) {
		if (!sp[i]) {
			sp[i] = i;			
			for (int j = i*i; j < SZ; j += i) 
			sp[j] = !sp[j] ? i : sp[j];
		}
	}
}

int divisor_count(int x) {
	int count = 1;
	while (x > 1) {
		int prime = sp[x];
		int power = 0;
		while (sp[x] == prime and x > 1) {
			x /= sp[x];
			power++;
		}
		count *= (power + 1);
	}
	return count;
}

int divisor_sum(int x) {
	int count = 1;
	while (x > 1) {
		int prime = sp[x];
		int power = 0;
		while (sp[x] == prime and x > 1) {
			x /= sp[x];
			power++;
		}
		count *= ((int)pow(prime, power + 1) - 1) / (prime - 1);
	}
	return count;
}
