use std::collections::HashSet;

pub fn part1(input: &str) -> Result<(), ()> {
    let sum = input
        .lines()
        .flat_map(|line| line.parse::<i32>())
        .fold(0, |acc, n| acc + n);
    println!("Feq sum: {}", sum);
    Ok(())
}

pub fn part2(input: &str) -> Result<(), ()> {
    let mut seen = HashSet::new();
    let mut freq = 0;

    loop {
        for line in input.lines() {
            let n: i32 = line.parse().expect("Unable to parse line");

            freq += n;

            if seen.contains(&freq) {
                println!("Found {} twice first", freq);
                return Ok(());
            }
            seen.insert(freq);
        }
    }
}
