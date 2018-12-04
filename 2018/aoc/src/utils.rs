use std::fs::File;
use std::io::{self, BufReader, Read};

pub fn read_file(path: &str) -> io::Result<String> {
    let mut input = String::new();

    open_file_reader(path)
        .and_then(|mut reader| Ok(reader.read_to_string(&mut input)))
        .and_then(|_| Ok(input))
}

fn open_file_reader(path: &str) -> io::Result<BufReader<File>> {
    File::open(path).and_then(|file| Ok(BufReader::new(file)))
}
