extern crate structopt;

mod day1;
mod day2;
mod utils;

use structopt::StructOpt;

#[derive(Debug, StructOpt)]
#[structopt(name = "AoC", about = "CLI for AoC 2018 answers")]
struct Cli {
    day: u32,
}

fn main() {
    match Cli::from_args() {
        Cli { day: 1 } => do_day1(),
        Cli { day: 2 } => do_day2(),
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

fn do_day2() {
    let file = "./inputs/day2.txt";

    match utils::read_file(file) {
        Ok(input) => {
            let input_strs: Vec<&str> = input.lines().collect();
            let checksum = day2::part1(input_strs);
            println!("checksum: {}", checksum);
        }
        Err(io_error) => println!("{:?}", io_error),
    };
}
