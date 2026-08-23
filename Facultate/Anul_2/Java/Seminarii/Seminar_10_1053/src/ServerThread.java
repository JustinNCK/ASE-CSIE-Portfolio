import java.io.*;
import java.net.Socket;


public class ServerThread extends Thread {
    private Socket client = null;
    private static int nrClient = 0;

    public ServerThread(Socket client) {
        super("Client_"+(++nrClient));
        this.client = client;
    }

    @Override
    public void run()
    {
        try (var in = new DataInputStream(client.getInputStream());
             var out = new DataOutputStream(client.getOutputStream());) {
            System.out.println("Conexiune acceptata de la " + client.getRemoteSocketAddress() +
                    " nume " + this.getName());

            while (true) {
                // 1. preluare cerere de la client
                String cerere = in.readUTF();

                // 2. prelucrare cerere client
                sleep(500);
                System.out.println(this.getName() + ": " + cerere);

                // 3. pregatire raspuns pentru client
                String raspuns = "Ecou server: " + cerere;

                // 4. trimitere raspuns catre client
                out.writeUTF(raspuns);
            }

        } catch (IOException e) {
            if (e instanceof EOFException)
                System.out.println("Deconectare " + this.getName());
            else
                throw new RuntimeException(e);
        } catch (InterruptedException e) {
            throw new RuntimeException(e);
        }

    }
}

