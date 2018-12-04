use std::fs::File;
use std::io::{self, BufRead, BufReader, Lines};

type LineReader = Lines<BufReader<File>>;

pub fn read_file(path: &str) -> io::Result<impl Iterator<Item = i32>> {
    open_file_reader(path)
        .and_then(|reader| Ok(reader.lines()))
        .and_then(|lines| Ok(parse_line(lines)))
}

fn open_file_reader(path: &str) -> io::Result<BufReader<File>> {
    File::open(path).and_then(|file| Ok(BufReader::new(file)))
}

fn parse_line(lines: LineReader) -> impl Iterator<Item = i32> {
    lines.map(|l| l.unwrap().parse::<i32>().unwrap())
}
