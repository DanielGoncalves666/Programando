use std::io;

fn main() {
	let mut a = String::new();
	let mut b = String::new();
	
	io::stdin()
		.read_line(&mut a)
		.expect("Falha");
	io::stdin()
		.read_line(&mut b)
		.expect("Falha");

	let a: i32 = a.trim().parse().expect("Não é um número");
	let b: i32 = b.trim().parse().expect("Não é um número");

	let soma = a + b;

	println!("X = {}",soma);
}