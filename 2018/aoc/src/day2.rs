use std::collections::HashMap;

type LetterCountMap = HashMap<char, isize>;
type TwoCount = isize;
type ThreeCount = isize;

pub fn part1(input: Vec<&str>) -> isize {
    let mut number_of_two = 0;
    let mut number_of_three = 0;

    for s in input.iter() {
        let map = s.chars().fold(HashMap::new(), |mut map, c| {
            count_char(&mut map, c);
            map
        });

        let (two, three) = get_counts(map);

        number_of_two += two;
        number_of_three += three;
    }

    number_of_two * number_of_three
}

fn count_char(char_map: &mut LetterCountMap, character: char) {
    char_map
        .entry(character)
        .and_modify(|value| *value += 1)
        .or_insert(1);
}

fn get_counts(map: LetterCountMap) -> (TwoCount, ThreeCount) {
    map.iter()
        .fold((0, 0), |mut counts, (_, amount)| match amount {
            2 => {
                if counts.0 == 0 {
                    counts.0 = 1;
                }

                counts
            }
            3 => {
                if counts.1 == 0 {
                    counts.1 = 1;
                }

                counts
            }
            _ => counts,
        })
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn it_works() {
        let input = vec![
            "abcdef", "bababc", "abbcde", "abcccd", "aabcdd", "abcdee", "ababab",
        ];

        assert_eq!(part1(input), 12);
    }
}
