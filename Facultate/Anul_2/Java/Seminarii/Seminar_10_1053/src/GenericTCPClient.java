import java.io.*;
import java.net.ConnectException;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.Objects;
import static java.lang.System.exit;


public class GenericTCPClient {
    public static void main(String[] args) {

        // "localhost" este numele asociat adresei de IP 127.0.0.1
        if (args.length != 2) {
            System.err.println("Numar incorect de argumente! Utilizare: java GenericTCPClient <port> <ip address>");
            System.exit(-1);
        }

        int port = Integer.parseInt(args[0]);
        InetAddress adresaIP = null;
        try {
            adresaIP = InetAddress.getByName(args[1]);
        } catch (UnknownHostException e) {
            throw new RuntimeException(e);
        }

        try (var client = new Socket(adresaIP, port);
             var out = new DataOutputStream(client.getOutputStream());
             var in = new DataInputStream(client.getInputStream());) {
            System.out.println("Conexiune socket la server " + adresaIP +
                    " port " + port + " realizata cu succes!");

            var citesteLinie = new BufferedReader(new InputStreamReader(System.in));
            while (true) {
                // 1. pregatire cerere de trimis catre server
                String mesaj = citesteLinie.readLine();
                if (mesaj.equalsIgnoreCase("exit")) {
                    in.close();
                    out.close();
                    client.close();
                    System.exit(0);
                }

                // 2. trimitere cerere catre client
                out.writeUTF(mesaj);

                // 3. preluare raspuns de la server
                String raspuns = in.readUTF();

                // 4. prelucrare raspuns primit de la server
                System.out.println(raspuns);

            }

        } catch (IOException e) {
            if (e instanceof ConnectException)
                System.out.println("Conexiune la server esuata!");
            else
                throw new RuntimeException(e);
        }
    }
}
