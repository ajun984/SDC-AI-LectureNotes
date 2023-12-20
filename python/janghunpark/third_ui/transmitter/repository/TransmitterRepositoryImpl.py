import socket
from datetime import datetime
from time import sleep

from transmitter.repository.TransmitterRepository import TransmitterRepository


# Instance setting 은 이렇게 하는구나
class TransmitterRepositoryImpl(TransmitterRepository):
    # __ : private 을 의미
    # 그렇지 않으면 c++ 에서 public 과 같은 위치
    __instance = None

    # Instance 생성자
    def __new__(cls):
        if cls.__instance is None:
            cls.__instance = super().__new__(cls)
        return cls.__instance

    def __init__(self):
        print("TransmitterRepositoryImpl 생성자 호출")

    # Instance 와 관련된 코드는 Interface 에 작성하지 않네 ?
    # python 의 메서드 정리
    # 1. 인스턴스 메서드 : 인스턴스 변수에 엑세스 가능하도록 메서드의 첫 번째 파라미터에 self 를 씀
    # 2. 클래스 메서드 : 클래스를 의미하는 cls 라는 파라미터를 전달 받아 클래스 변수에 엑세스 할 수 있음
    @classmethod
    def getInstance(cls):
        if cls.__instance is None:
            cls.__instance = cls()
        return cls.__instance

    # clientSocket 객체를 전달 받아서 그 안의 socket 에 메시지를 담아 전달
    def transmitCommand(self, clientSocketObject):
        while True:
            try:
                sendMessage = "참 쉽죠 ?"
                clientSocket = clientSocketObject.getSocket()
                clientSocket.sendall(sendMessage.encode())
                print('{} command 전송 [{}]'.format(datetime.now(), sendMessage))

            except (socket.error, BrokenPipeError) as exception:
                print(f"사용자 연결 종료")
                return None

            except socket.error as exception:
                print(f"전송 중 에러 발생: str{exception}")
                sleep(0.5)

            except Exception as exception:
                print("원인을 알 수 없는 에러가 발생하였습니다")

            sleep(2)


