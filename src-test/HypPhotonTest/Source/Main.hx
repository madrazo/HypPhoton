import nme.display.Bitmap;
import nme.display.Sprite;
import nme.Assets;
import nme.Lib;
import nme.events.Event;

import fr.hyperfiction.HypPhoton;

class Main extends Sprite {
	
	private var _photon : HypPhoton;
	private var _bRoom : Bool;

	private var m_state:Int;
	static inline var INITIALIZED:Int = 1;
	static inline var CONNECTING:Int = 2;
	static inline var CONNECTED:Int = 3;
	static inline var JOINING:Int = 4;
	static inline var JOINED:Int = 5;
	static inline var RECEIVED_DATA:Int = 6;
	static inline var LEAVING:Int = 7;
	static inline var LEFT:Int = 8;
	static inline var DISCONNECTING:Int = 9;
	static inline var DISCONNECTED:Int = 10;
	
	public function new () {
		
		super ();

		var bitmap = new Bitmap (Assets.getBitmapData ("assets/nme.png"));
		addChild (bitmap);
		
		bitmap.x = (Lib.current.stage.stageWidth - bitmap.width) / 2;
		bitmap.y = (Lib.current.stage.stageHeight - bitmap.height) / 2;

		_photon = new HypPhoton( );
		_photon.onEvent = _onEvent;
		nme.Lib.current.stage.addEventListener( nme.events.Event.ENTER_FRAME , _onEnterframe);
		m_state = INITIALIZED;
	}

	private function _onEnterframe( e:Event ) : Void
	{
		if(m_state<2)
			trace("state: "+m_state);

		switch(m_state)
		{
			case INITIALIZED: _photon.connect(""); m_state = CONNECTING;
			case CONNECTED:  _photon.joinOrCreate_room( 2 ); m_state = JOINING;
			case JOINED:  sendData();
			case RECEIVED_DATA:  _photon.leaveRoom(); m_state = LEAVING;
			case LEFT:  _photon.disconnect(); m_state = DISCONNECTING;
			case DISCONNECTED:  m_state = INITIALIZED;
		}

		_photon.update( );
	}

	private function sendData()
	{
		haxe.Timer.delay( function( ){
			trace("send test");
			_photon.send("testéééééé");
		},1000 );
	}
	
	private function _onEvent( s : String , v : String ) : Void{
			trace("_onEvent ::: "+s+" - "+v);

			switch( s ){

				case PhotonEvents.CLIENT_ERROR:

				case PhotonEvents.CONNECT_ERROR:
					m_state = DISCONNECTING;

				case PhotonEvents.CONNECT_SUCCESS:
					m_state = CONNECTED;
					

				case PhotonEvents.CREATE_ROOM_ERROR:
					m_state = CONNECTED;

				case PhotonEvents.CREATE_ROOM_SUCCESS:
					m_state = JOINED;

				case PhotonEvents.DEBUG_RETURN:
					trace("DEBUG_RETURN ["+s+"] ["+v+"]");

				case PhotonEvents.DISCONNECT_RETURN:

				case PhotonEvents.GOT_QUEUE_RETURN:

				case PhotonEvents.JOINED_LOBBY_SUCCESS:

				case PhotonEvents.JOIN_RANDOM_ROOM_ERROR:
					trace("JOIN_RANDOM_ROOM_ERROR");
					trace("create room");
					//_photon.createRoom( "2" , 2 );

					m_state = CONNECTED;

				case PhotonEvents.JOIN_RANDOM_ROOM_SUCCESS:
					trace("JOIN_RANDOM_ROOM_SUCCESS");
					m_state = JOINED;

				case PhotonEvents.JOIN_ROOM_ERROR:
					m_state = CONNECTED;

				case PhotonEvents.JOIN_ROOM_SUCCESS:
					//m_state = LEFT;

				case PhotonEvents.LEAVE_ROOM_FAILED:
					m_state = DISCONNECTING;

				case PhotonEvents.LEAVE_ROOM_SUCCESS:

				case PhotonEvents.LOBBY_LEAVE:

				case PhotonEvents.PLAYER_JOINED_ROOM:
					//_bRoom = true;
					//_photon.send("test");

				case PhotonEvents.PLAYER_LEAVED_ROOM:

				case PhotonEvents.SERVER_ERROR:

				case PhotonEvents.SERVER_WARNING:


			}
		}
}
