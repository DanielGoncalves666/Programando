use std::io;

fn main() {
	let mut a = String::new();
	let mut b = String::new();
	let prod: i32;

	io::stdin()
		.read_line(&mut a)
		.expect("Falha 1");
	
	io::stdin()
		.read_line(&mut b)
		.expect("Falha 2");

	let a: i32 = a.trim().parse().expect("Falha 3");
	let b: i32 = b.trim().parse().expect("Falha 4");

	prod = a * b;

	println!("PROD = {}",prod);
}