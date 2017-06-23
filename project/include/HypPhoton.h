#ifndef HypPhoton_H
#define HypPhoton_H

#include <stdio.h>
#include <sstream>

//#include "LoadBalancingListener.h"
//#include "LoadBalancingClient.h"
//#include "LoadBalancingPlayer.h"

#include "LoadBalancing-cpp/inc/Listener.h"
#include "LoadBalancing-cpp/inc/Client.h"
#include "LoadBalancing-cpp/inc/Player.h"
//#include "Common-cpp/inc/Enums/DebugLevel.h"

#include "PeerStates.h"

#define CLIENT_ERROR			"CLIENT_ERROR"
#define CONNECT_ERROR			"CONNECT_ERROR"
#define CONNECT_SUCCESS			"CONNECT_SUCCESS"
#define CREATE_ROOM_ERROR		"CREATE_ROOM_ERROR"
#define CREATE_ROOM_SUCCESS		"CREATE_ROOM_SUCCESS"
#define DEBUG_RETURN			"DEBUG_RETURN"
#define DISCONNECT_RETURN		"DISCONNECT_RETURN"
#define GOT_QUEUE_RETURN			"GOT_QUEUE_RETURN"
#define JOINED_LOBBY_SUCCESS		"JOINED_LOBBY_SUCCESS"
#define JOIN_RANDOM_ROOM_ERROR	"JOIN_RANDOM_ROOM_ERROR"
#define JOIN_RANDOM_ROOM_SUCCESS	"JOIN_RANDOM_ROOM_SUCCESS"
#define JOIN_ROOM_ERROR			"JOIN_ROOM_ERROR"
#define JOIN_ROOM_SUCCESS		"JOIN_ROOM_SUCCESS"
#define LEAVE_ROOM_FAILED		"LEAVE_ROOM_FAILED"
#define LEAVE_ROOM_SUCCESS		"LEAVE_ROOM_SUCCESS"
#define LOBBY_LEAVE			 	"LOBBY_LEAVE"
#define PLAYER_JOINED_ROOM		"PLAYER_JOINED_ROOM"
#define PLAYER_LEAVED_ROOM		"PLAYER_LEAVED_ROOM"
#define SERVER_ERROR			"SERVER_ERROR"
#define SERVER_WARNING			"SERVER_WARNING"
#define EVENT			 		"EVENT"

//using namespace ExitGames;
//using namespace ExitGames::LoadBalancing;

class HypPhoton : private ExitGames::LoadBalancing::Listener{

	public:
		static HypPhoton& Instance();
		void connect( const char *sHost );
		void disconnect( );
		void update( void );
		void joinRandom_room( int maxPlayers );
		void joinOrCreate_room( int maxPlayers );
		void createRoom( const char *sName , int maxPlayers );
		void send( const char *sText );
		void setUser_name( const char *sUser_name, int n );
		const char * getState( void );
		void hideRoom( void );
		void joinLobby( void );
		void start( void );
		void leaveRoom( void );
		const char * getRoom_desc( void );
		const char * getRoom_players( void );
		void addRoom_prop( const char *k , const char *v );
		const char* getRoom_prop( const char *key );

	private:
		//HypPhoton (const HypPhoton&){}
		HypPhoton( );
		~HypPhoton( );
		static HypPhoton m_instance;
		const char * convert( int code );

		// receive and print out debug out here
			virtual void debugReturn(int debugLevel, const ExitGames::Common::JString& string);

			// implement your error-handling here
			virtual void connectionErrorReturn(int errorCode);
			virtual void clientErrorReturn(int errorCode);
			virtual void warningReturn(int warningCode);
			virtual void serverErrorReturn(int errorCode);

			// events, triggered by certain operations of all players in the same room
			virtual void joinRoomEventAction(int playerNr, const ExitGames::Common::JVector<int>& playernrs, const ExitGames::LoadBalancing::Player& player);
			virtual void leaveRoomEventAction(int playerNr, bool isInactive);//

			virtual void customEventAction(int playerNr, nByte eventCode, const ExitGames::Common::Object& eventContent);//

		// callbacks for operations on server
			virtual void connectReturn(int errorCode, const ExitGames::Common::JString& errorString, const ExitGames::Common::JString& cluster);
			virtual void disconnectReturn(void);
			virtual void createRoomReturn(int localPlayerNr, const ExitGames::Common::Hashtable& roomProperties, const ExitGames::Common::Hashtable& playerProperties, int errorCode, const ExitGames::Common::JString& errorString);
    		virtual void joinOrCreateRoomReturn(int localPlayerNr, const ExitGames::Common::Hashtable& roomProperties, const ExitGames::Common::Hashtable& playerProperties, int errorCode, const ExitGames::Common::JString& errorString);
			virtual void joinRoomReturn(int localPlayerNr, const ExitGames::Common::Hashtable& roomProperties, const ExitGames::Common::Hashtable& playerProperties, int errorCode, const ExitGames::Common::JString& errorString);
			virtual void joinRandomRoomReturn(int localPlayerNr, const ExitGames::Common::Hashtable& roomProperties, const ExitGames::Common::Hashtable& playerProperties, int errorCode, const ExitGames::Common::JString& errorString);
			virtual void leaveRoomReturn(int errorCode, const ExitGames::Common::JString& errorString);
			virtual void joinLobbyReturn(void);
			virtual void leaveLobbyReturn(void);
/**///			virtual void onFindFriendsResponse(void) {}
/**///			virtual void onLobbyStatsResponse(const ExitGames::Common::JVector<LobbyStatsResponse>& /*lobbyStats*/) {}
/**///			virtual void webRpcReturn(int /*errorCode*/, const ExitGames::Common::JString& /*errorString*/, const ExitGames::Common::JString& /*uriPath*/, int /*resultCode*/, const ExitGames::Common::Dictionary<ExitGames::Common::Object, ExitGames::Common::Object>& /*returnData*/) {}

#if 0
			// info, that certain values have been updated
			virtual void onRoomListUpdate(void) {}
			virtual void onRoomPropertiesChange(const ExitGames::Common::Hashtable& /*changes*/) {}
			virtual void onPlayerPropertiesChange(int /*playerNr*/, const ExitGames::Common::Hashtable& /*changes*/) {}
			virtual void onAppStatsUpdate(void) {}
			virtual void onLobbyStatsUpdate(const ExitGames::Common::JVector<LobbyStatsResponse>& /*lobbyStats*/) {}
			virtual void onCacheSliceChanged(int /*cacheSliceIndex*/) {}
			// custom authentication
			virtual void onCustomAuthenticationIntermediateStep(const ExitGames::Common::Dictionary<ExitGames::Common::JString, ExitGames::Common::Object>& /*customResponseData*/){}

			// receive available server regions during connect workflow (if you have specified in the constructor, that you want to select a region)
			virtual void onAvailableRegions(const ExitGames::Common::JVector<ExitGames::Common::JString>& /*availableRegions*/, const ExitGames::Common::JVector<ExitGames::Common::JString>& /*availableRegionServers*/){}

			virtual void onSecretReceival(const ExitGames::Common::JString& /*secret*/){}
#endif

#if 0
		virtual void connectReturn(int errorCode, const ExitGames::Common::JString& errorString);

		virtual void createRoomReturn(int localPlayerNr, const ExitGames::Common::Hashtable& gameProperties, const ExitGames::Common::Hashtable& playerProperties, int errorCode, const ExitGames::Common::JString& errorString);
//		virtual void customEventAction(int playerNr, nByte eventCode, const ExitGames::Common::Hashtable& eventContent);
//		virtual void debugReturn(ExitGames::Common::DebugLevel::DebugLevel debugLevel, const ExitGames::Common::JString& string);
//		virtual void debugReturn(const ExitGames::Common::JString& string);
		virtual void disconnectReturn(void);
		virtual void gotQueuedReturn(void);
		virtual void joinLobbyReturn(void);
		virtual void joinRandomRoomReturn(int localPlayerNr, const ExitGames::Common::Hashtable& gameProperties, const ExitGames::Common::Hashtable& playerProperties, int errorCode, const ExitGames::Common::JString& errorString);
//		virtual void joinRoomEventAction(int playerNr, const ExitGames::Common::JVector<int>& playernrs, const ExitGames::LoadBalancing::Player& player);
		virtual void joinRoomReturn(int localPlayerNr, const ExitGames::Common::Hashtable& gameProperties, const ExitGames::Common::Hashtable& playerProperties, int errorCode, const ExitGames::Common::JString& errorString);
		virtual void leaveLobbyReturn(void);
//		virtual void leaveRoomEventAction(int playerNr);
		virtual void leaveRoomReturn(int errorCode, const ExitGames::Common::JString& errorString);
#endif

		ExitGames::LoadBalancing::Client mLoadBalancingClient;

		ExitGames::Common::Logger mLogger;

};
#endif
