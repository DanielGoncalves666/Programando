use std::io;

fn main() {
	let pi = 3.14159;
	let handle = io::stdin();
	let mut raio = String::new();

	handle.read_line(&mut raio).expect("Falha 1");

	let raio: f64 = raio.trim().parse().expect("Falha 2");
	let volume = (4.0 / 3.0) * pi * raio * raio * raio;

	println!("VOLUME = {:.3}",volume);
}