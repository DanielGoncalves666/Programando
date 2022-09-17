use std::io;

fn main() {
	let mut a = String::new();
	let mut b = String::new();

	io::stdin()
		.read_line(&mut a)
		.expect("Falha 1");
	
	io::stdin()
		.read_line(&mut b)
		.expect("Falha 2");

	let a: f64 = a.trim().parse().expect("Falha 3");
	let b: f64 = b.trim().parse().expect("Falha 4");

	let media = (a * 3.5 + b * 7.5) / 11.0;

	println!("MEDIA = {:.5}",media);
}