use std::{env, process, f64};

fn main() {

    let mut rounds: u64 = 100000;

    if env::args().len() > 2 {

        println!("Accepts only one u64 argument.");
        process::exit(0);

    } else if env::args().len() > 1 {

        rounds = env::args().nth(1).unwrap().parse::<u64>().unwrap();

    }

    println!("Rounds: {}", rounds);

    let mut c_pi: f64 = 4.0;

    for i in 0..rounds {

        let n: f64 = (i * 2 + 3) as f64;

        if i % 2 == 0 {

            c_pi += -4.0 / n;

        } else {

            c_pi += 4.0 / n;

        }

    }

    println!("PI: {}", c_pi);
    println!("PI is actually: {}", f64::consts::PI);

}


