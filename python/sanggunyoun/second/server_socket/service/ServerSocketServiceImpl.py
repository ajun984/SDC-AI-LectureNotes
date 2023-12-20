from server_socket.repository.ServerSocketRepositoryImpl import ServerSocketRepositoryImpl
from server_socket.service.ServerSocketService import ServerSocketService


class ServerSocketServiceImpl(ServerSocketService):
    __instance = None

    def __new__(cls, repository):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
            cls.__instance.repository = repository
        return cls.__instance

    def __init__(self, repository):
        print("ServerSocketServiceImpl 생성자 호출")
        self.__serverSocketRepository = ServerSocketRepositoryImpl()
        # self.__clientSocketRepository = ClientSocketRepositoryImpl()

    @classmethod
    def getInstance(cls, repository=None):
        if cls.__instance is None:
            cls.__instance = cls(repository)
        return cls.__instance

    def createServerSocket(self, host, port):
        return self.__serverSocketRepository.create(host, port)

    def setSocketOption(self, apiControlLevel, OptionName):
        self.__serverSocketRepository.setSocketOption(apiControlLevel, OptionName)

    def bindServerSocket(self):
        self.__serverSocketRepository.bindServerSocket()

    def setServerListenNumber(self, howManyAccessHere):
        self.__serverSocketRepository.setListenNumber(howManyAccessHere)

    def setBlockingOperation(self):
        self.__serverSocketRepository.setBlockingOperation()

    def acceptClientSocket(self, queue):
        clientSocket, clientAddress = self.__serverSocketRepository.acceptClientSocket()

        if clientSocket is None:
            return

        print("clientSocket: {}, clientAddress: {}".format(clientSocket, clientAddress))
        queue.put((clientSocket, clientAddress))





