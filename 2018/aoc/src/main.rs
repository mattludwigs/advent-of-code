extern crate structopt;

mod utils;

use structopt::StructOpt;

#[derive(Debug, StructOpt)]
#[structopt(name = "AoC", about = "CLI for AoC 2018 answers")]
struct Cli {
    day: u32,
}

fn main() {
    match Cli::from_args() {
        Cli { day: 1 } => day1(),
        _ => println!("Invalid Day!"),
    }
}

fn day1() {
    let file1 = "./inputs/day1.txt";

    match utils::read_file(file1) {
        Ok(input) => {
            let sum = input.fold(0, |acc, n| acc + n);
            println!("{}", sum);
        }
        Err(io_error) => println!("{:?}", io_error),
    }
}
