import java.io.*;
import java.util.*;

public class headmasters_pk {

	void solve() throws IOException {
		int n = nextInt();
		int[] con = new int[n];
		int m = nextInt();
		for (int i = 0; i < m; i++) {
			int l = nextInt() - 1;
			int r = nextInt() - 1;
			con[l] |= 1 << r;
			con[r] |= 1 << l;
		}
		int[] dp = new int[1 << n];
		int[] cnt = new int[1 << n];
		Arrays.fill(dp, Integer.MAX_VALUE);
		dp[0] = 0;
		for (int mask = 0; mask < 1 << n; mask++) {
			for (int i = 0; i < n; i++) {
				if ((mask & (1 << i)) > 0)
					continue;
				cnt[mask | (1 << i)] = cnt[mask]
						- Integer.bitCount(con[i] & mask)
						+ Integer.bitCount(con[i] & (~mask));
				dp[mask | (1 << i)] = Math.min(dp[mask] + cnt[mask], dp[mask
						| (1 << i)]);
			}
		}
		out.println(dp[(1 << n) - 1]);
	}

	BufferedReader br;
	StringTokenizer st;
	PrintWriter out;

	void run() {
		try {
			br = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(System.out);

			br = new BufferedReader(new FileReader(new File("headmasters.in")));
			out = new PrintWriter("headmasters.out");
			solve();

			out.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	public static void main(String[] args) {
		new headmasters_pk().run();
	}

	String nextToken() throws IOException {
		while ((st == null) || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine());
		return st.nextToken();
	}

	int nextInt() throws NumberFormatException, IOException {
		return Integer.parseInt(nextToken());
	}

	double nextDouble() throws NumberFormatException, IOException {
		return Double.parseDouble(nextToken());
	}

	long nextLong() throws NumberFormatException, IOException {
		return Long.parseLong(nextToken());
	}
}
