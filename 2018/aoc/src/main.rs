extern crate structopt;

mod utils;
mod day1;

use structopt::StructOpt;

#[derive(Debug, StructOpt)]
#[structopt(name = "AoC", about = "CLI for AoC 2018 answers")]
struct Cli {
    day: u32,
}

fn main() {
    match Cli::from_args() {
        Cli { day: 1 } => do_day1(),
        _ => println!("Invalid Day!"),
    }
}

fn do_day1() {
    let file1 = "./inputs/day1.txt";
    match utils::read_file(file1) {
        Ok(input) => {
            day1::part1(&input).expect("Part1 failed");
            day1::part2(&input).expect("Part 2 failed");
        }
        Err(io_error) => println!("{:?}", io_error),
    };
}
