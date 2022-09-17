use std::env; // enviromental module from the standart libray, which allows us to get a string from the command line
use std::process; // to exit the program without panicking

use minigrep::Config;

fn main() {
    let args: Vec<String> = env::args().collect();
    // the args function get all the arguments from the command line and the collect function
    // transform then into a collection  

    let config = Config::new(&args).unwrap_or_else(|err| {
        eprintln!("Problem parsing arguments: {err}");
        process::exit(1);
    });

    println!("Searching for {}", config.query);
    println!("In file {}", config.filename);

    if let Err(e) = minigrep::run(config){
        eprintln!("Application error: {e}");

        process::exit(1);
    }
}