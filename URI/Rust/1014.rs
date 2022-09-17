use std::io;

fn main() {
	let handle = io::stdin();
	let mut distancia = String::new();
	let mut combustivel = String::new();

	handle.read_line(&mut distancia).expect("Falha 1");
	handle.read_line(&mut combustivel).expect("Falha 2");

	let distancia: f64 = distancia.trim().parse().expect("Falha 3");
	let combustivel: f64 = combustivel.trim().parse().expect("Falha 4");

	let cosumo_medio = distancia / combustivel;

	println!("{:.3} km/l",cosumo_medio);
}