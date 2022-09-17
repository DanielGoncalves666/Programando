use std::io;

fn main() {
	let mut raio = String::new();
	let area: f64;
	let pi: f64 =  3.14159;

	io::stdin()
		.read_line(&mut raio)
		.expect("Falha");
	
	let raio: f64 = raio.trim().parse().expect("Não é ponto flutuante");

	area = pi * raio * raio;

	println!("A={:.4}",area);
}
