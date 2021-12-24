// https://www.reddit.com/r/rust/comments/rn7ozz/find_perfect_number_comparison_go_java_rust/

use {
    rayon::prelude::*,
    std::{collections::HashMap, time::Instant},
};

const N: usize = 320000;
// const N: usize = 10_000_000;

// Original, takes about 68s (yes, 68 seconds) on an Core i7 6700 @ 3.4GHz
fn cal_perfs(n: usize) -> Vec<usize> {
    let mut nums = Vec::new();
    for i in 1..=n {
        let v = cal(i);
        if v.keys().sum::<usize>() == i {
            nums.push(i);
        }
    }
    nums
}

fn cal(n: usize) -> HashMap<usize, bool> {
    let mut nums = HashMap::with_capacity(128); // Avoid a bunch of tiny re-allocations
    nums.insert(1, true);
    let mid = n / 2;
    for i in 2..=mid {
        if n % i == 0 {
            nums.insert(i, true);
            nums.insert(n / i, true);
        }
    }
    nums
}

// Optimized, takes about 320ms on an Core i7 6700 @ 3.4GHz
fn cal_perfs2(n: usize) -> Vec<usize> {
    (1..=n)
        .into_iter()
        .filter(|i| cal2(*i) == *i)
        .collect::<Vec<_>>()
}

fn cal2(n: usize) -> usize {
    (2..=(n as f64).sqrt() as usize)
        .into_iter()
        .filter_map(|i| if n % i == 0 { Some([i, n / i]) } else { None })
        .map(|a| a[0] + a[1])
        .sum::<usize>()
        + 1
}

// Optimized + Rayon, takes about 65ms on an Core i7 6700 @ 3.4GHz
fn cal_perfs3(n: usize) -> Vec<usize> {
    (1..=n)
        .into_par_iter()
        .filter_map(|i| if cal2(i) == i { Some(i) } else { None })
        .collect::<Vec<_>>()
}

fn main() {
    let start = Instant::now();
    let perf1 = cal_perfs(N);
    println!("Original: {:?}", start.elapsed());

    let start = Instant::now();
    let perf2 = cal_perfs2(N);
    println!("Optimized: {:?}", start.elapsed());

    let start = Instant::now();
    let perf3 = cal_perfs3(N);
    println!("Optimized + Rayon: {:?}", start.elapsed());

    println!("{:#?}", perf3);

    // Make sure our new implementations are doing the same thing
    assert_eq!(perf1, perf2);
    assert_eq!(perf1, perf3);
}
