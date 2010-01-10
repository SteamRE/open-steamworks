using System;
using System.Runtime.InteropServices;
using Steam4NET;

namespace Steam4NET
{
	public enum EServerMode
	{
		eServerModeInvalid = 0,
		eServerModeNoAuthentication = 1,
		eServerModeAuthentication = 2,
		eServerModeAuthenticationAndSecure = 3,
	}
	
	public enum k_EFriendFlags
	{
		k_EFriendFlagNone = 0,
		k_EFriendFlagBlocked = 1,
		k_EFriendFlagFriendshipRequested = 2,
		k_EFriendFlagImmediate = 4,
		k_EFriendFlagClanMember = 8,
		k_EFriendFlagOnGameServer = 16,
		k_EFriendFlagRequestingFriendship = 128,
		k_EFriendFlagRequestingInfo = 256,
		k_EFriendFlagIgnored = 512,
		k_EFriendFlagIgnoredFriend = 1024,
		k_EFriendFlagAll = 65535,
	}
	
	public enum ESNetSocketState
	{
		k_ESNetSocketStateInvalid = 0,
		k_ESNetSocketStateConnected = 1,
		k_ESNetSocketStateInitiated = 10,
		k_ESNetSocketStateLocalCandidatesFound = 11,
		k_ESNetSocketStateReceivedRemoteCandidates = 12,
		k_ESNetSocketStateChallengeHandshake = 15,
		k_ESNetSocketStateDisconnecting = 21,
		k_ESNetSocketStateLocalDisconnect = 22,
		k_ESNetSocketStateTimeoutDuringConnect = 23,
		k_ESNetSocketStateRemoteEndDisconnected = 24,
		k_ESNetSocketStateConnectionBroken = 25,
	}
	
	public enum ERegistrySubTree
	{
		k_ERegistrySubTreeNews = 0,
		k_ERegistrySubTreeApps = 1,
		k_ERegistrySubTreeSubscriptions = 2,
		k_ERegistrySubTreeGameServers = 3,
		k_ERegistrySubTreeFriends = 4,
		k_ERegistrySubTreeSystem = 5,
	}
	
	public enum ESteamBufferMethod
	{
		eSteamBufferMethodFBF = 0,
		eSteamBufferMethodNBF = 1,
	}
	
	public enum EPurchaseResultDetail
	{
		k_EPurchaseResultNoDetail = 0,
		k_EPurchaseResultAVSFailure = 1,
		k_EPurchaseResultInsufficientFunds = 2,
		k_EPurchaseResultContactSupport = 3,
		k_EPurchaseResultTimeout = 4,
		k_EPurchaseResultInvalidPackage = 5,
		k_EPurchaseResultInvalidPaymentMethod = 6,
		k_EPurchaseResultInvalidData = 7,
		k_EPurchaseResultOthersInProgress = 8,
		k_EPurchaseResultAlreadyPurchased = 9,
		k_EPurchaseResultWrongPrice = 10,
	}
	
	public enum EDenyReason
	{
		k_EDenyInvalidVersion = 1,
		k_EDenyGeneric = 2,
		k_EDenyNotLoggedOn = 3,
		k_EDenyNoLicense = 4,
		k_EDenyCheater = 5,
		k_EDenyLoggedInElseWhere = 6,
		k_EDenyUnknownText = 7,
		k_EDenyIncompatibleAnticheat = 8,
		k_EDenyMemoryCorruption = 9,
		k_EDenyIncompatibleSoftware = 10,
		k_EDenySteamConnectionLost = 11,
		k_EDenySteamConnectionError = 12,
		k_EDenySteamResponseTimedOut = 13,
		k_EDenySteamValidationStalled = 14,
		k_EDenySteamOwnerLeftGuestUser = 15,
	}
	
	public enum EUniverse
	{
		k_EUniverseInvalid = 0,
		k_EUniversePublic = 1,
		k_EUniverseBeta = 2,
		k_EUniverseInternal = 3,
		k_EUniverseDev = 4,
		k_EUniverseRC = 5,
		k_EUniverseMax = 6,
	}
	
	public enum ELeaderboardSortMethod
	{
		k_ELeaderboardSortMethodNone = 0,
		k_ELeaderboardSortMethodAscending = 1,
		k_ELeaderboardSortMethodDescending = 2,
	}
	
	public enum ESystemIMType
	{
		k_ESystemIMRawText = 0,
		k_ESystemIMInvalidCard = 1,
		k_ESystemIMRecurringPurchaseFailed = 2,
		k_ESystemIMCardWillExpire = 3,
		k_ESystemIMSubscriptionExpired = 4,
		k_ESystemIMTypeMax = 5,
	}
	
	public enum EBeginAuthSessionResult
	{
		k_EBeginAuthSessionResultOK = 0,
		k_EBeginAuthSessionResultInvalidTicket = 1,
		k_EBeginAuthSessionResultDuplicateRequest = 2,
		k_EBeginAuthSessionResultInvalidVersion = 3,
		k_EBeginAuthSessionResultGameMismatch = 4,
		k_EBeginAuthSessionResultExpiredTicket = 5,
	}
	
	public enum ESNetSocketConnectionType
	{
		k_ESNetSocketConnectionTypeNotConnected = 0,
		k_ESNetSocketConnectionTypeUDP = 1,
		k_ESNetSocketConnectionTypeUDPRelay = 2,
	}
	
	public enum ENotificationPosition
	{
		k_EPositionTopLeft = 0,
		k_EPositionTopRight = 1,
		k_EPositionBottomLeft = 2,
		k_EPositionBottomRight = 3,
	}
	
	public enum EAccountType
	{
		k_EAccountTypeInvalid = 0,
		k_EAccountTypeIndividual = 1,
		k_EAccountTypeMultiseat = 2,
		k_EAccountTypeGameServer = 3,
		k_EAccountTypeAnonGameServer = 4,
		k_EAccountTypePending = 5,
		k_EAccountTypeContentServer = 6,
		k_EAccountTypeClan = 7,
		k_EAccountTypeChat = 8,
		k_EAccountTypeP2PSuperSeeder = 9,
		k_EAccountTypeAnonUser = 10,
		k_EAccountTypeMax = 11,
	}
	
	public enum ESteamSubscriptionBillingInfoType
	{
		ePaymentCardInfo = 1,
		ePrepurchasedInfo = 2,
		eAccountBillingInfo = 3,
		eExternalBillingInfo = 4,
		ePaymentCardReceipt = 5,
		ePrepurchaseReceipt = 6,
		eEmptyReceipt = 7,
	}
	
	public enum EBillingType
	{
		eNoCost = 0,
		eBillOnceOnly = 1,
		eBillMonthly = 2,
		eProofOfPrepurchaseOnly = 3,
		eGuestPass = 4,
		eHardwarePromo = 5,
		eGift = 6,
		eAutoGrant = 7,
		eNumBillingTypes = 8,
	}
	
	public enum EChatSteamIDInstanceFlags
	{
		k_EChatAccountInstanceMask = 4095,
		k_EChatInstanceFlagClan = 524288,
		k_EChatInstanceFlagLobby = 262144,
	}
	
	public enum ESteamServerType
	{
		eSteamValveCDKeyValidationServer = 0,
		eSteamHalfLifeMasterServer = 1,
		eSteamFriendsServer = 2,
		eSteamCSERServer = 3,
		eSteamHalfLife2MasterServer = 4,
		eSteamRDKFMasterServer = 5,
		eMaxServerTypes = 6,
	}
	
	public enum EAppUsageEvent
	{
		k_EAppUsageEventGameLaunch = 1,
		k_EAppUsageEventGameLaunchTrial = 2,
		k_EAppUsageEventMedia = 3,
		k_EAppUsageEventPreloadStart = 4,
		k_EAppUsageEventPreloadFinish = 5,
		k_EAppUsageEventMarketingMessageView = 6,
		k_EAppUsageEventInGameAdViewed = 7,
		k_EAppUsageEventGameLaunchFreeWeekend = 8,
	}
	
	public enum ELeaderboardDisplayType
	{
		k_ELeaderboardDisplayTypeNone = 0,
		k_ELeaderboardDisplayTypeNumeric = 1,
		k_ELeaderboardDisplayTypeTimeSeconds = 2,
		k_ELeaderboardDisplayTypeTimeMilliSeconds = 3,
	}
	
	public enum ECurrencyCode
	{
		k_ECurrencyCodeInvalid = 0,
		k_ECurrencyCodeUSD = 1,
		k_ECurrencyCodeGBP = 2,
		k_ECurrencyCodeEUR = 3,
		k_ECurrencyCodeMax = 4,
	}
	
	public enum EGCMsgResponse
	{
		k_EGCMsgResponseOK = 0,
		k_EGCMsgResponseDenied = 1,
		k_EGCMsgResponseServerError = 2,
		k_EGCMsgResponseTimeout = 3,
		k_EGCMsgResponseInvalid = 4,
		k_EGCMsgResponseNoMatch = 5,
		k_EGCMsgResponseUnknownError = 6,
		k_EGCMsgResponseNotLoggedOn = 7,
	}
	
	public enum ESteamAPICallFailure
	{
		k_ESteamAPICallFailureNone = -1,
		k_ESteamAPICallFailureSteamGone = 0,
		k_ESteamAPICallFailureNetworkFailure = 1,
		k_ESteamAPICallFailureInvalidHandle = 2,
		k_ESteamAPICallFailureMismatchedCallback = 3,
	}
	
	public enum EPurchaseStatus
	{
		k_EPurchasePending = 0,
		k_EPurchaseSucceeded = 1,
		k_EPurchaseFailed = 2,
		k_EPurchaseRefunded = 3,
		k_EPurchaseInit = 4,
		k_EPurchaseChargedback = 5,
		k_EPurchaseRevoked = 6,
	}
	
	public enum ESteamUserStatType
	{
		k_ESteamUserStatTypeINVALID = 0,
		k_ESteamUserStatTypeINT = 1,
		k_ESteamUserStatTypeFLOAT = 2,
		k_ESteamUserStatTypeAVGRATE = 3,
		k_ESteamUserStatTypeACHIEVEMENTS = 4,
		k_ESteamUserStatTypeGROUPACHIEVEMENTS = 5,
	}
	
	public enum EDepotBuildStatus
	{
		k_EDepotBuildStatusInvalid = -1,
		k_EDepotBuildStatusFailed = 0,
		k_EDepotBuildStatusProcessingConfig = 1,
		k_EDepotBuildStatusProcessingData = 2,
		k_EDepotBuildStatusUploadingData = 3,
		k_EDepotBuildStatusCompleted = 4,
	}
	
	public enum ELicenseFlags
	{
		k_ELicenseFlagRenew = 1,
		k_ELicenseFlagRenewalFailed = 2,
		k_ELicenseFlagPending = 4,
		k_ELicenseFlagExpired = 8,
		k_ELicenseFlagCancelledByUser = 16,
		k_ELicenseFlagCancelledByAdmin = 32,
	}
	
	public enum EAppState
	{
		k_EAppStateDownloading = 0,
		k_EAppStatePaused = 1,
		k_EAppStateDownloadComplete = 2,
	}
	
	public enum ELobbyType
	{
		k_ELobbyTypeFriendsOnly = 1,
		k_ELobbyTypePublic = 2,
	}
	
	public enum EChatRoomType
	{
		k_EChatRoomTypeFriend = 1,
		k_EChatRoomTypeMUC = 2,
		k_EChatRoomTypeLobby = 3,
	}
	
	public enum EFriendMsgType
	{
		k_EFriendMsgTypeChat = 1,
		k_EFriendMsgTypeTyping = 2,
		k_EFriendMsgTypeInvite = 3,
		k_EFriendMsgTypeChatSent = 4,
	}
	
	public enum ESteamPaymentCardType
	{
		eVisa = 1,
		eMaster = 2,
		eAmericanExpress = 3,
		eDiscover = 4,
		eDinnersClub = 5,
		eJCB = 6,
	}
	
	public enum EIFaceResult
	{
		IFACE_OK = 0,
		IFACE_FAILED = 1,
	}
	
	public enum EFriendRelationship
	{
		k_EFriendRelationshipNone = 0,
		k_EFriendRelationshipBlocked = 1,
		k_EFriendRelationshipRequestRecipient = 2,
		k_EFriendRelationshipFriend = 3,
		k_EFriendRelationshipRequestInitiator = 4,
		k_EFriendRelationshipIgnored = 5,
		k_EFriendRelationshipIgnoredFriend = 6,
	}
	
	public enum EMatchMakingServerResponse
	{
		eServerResponded = 0,
		eServerFailedToRespond = 1,
		eNoServersListedOnMasterServer = 2,
	}
	
	public enum ELobbyComparison
	{
		k_ELobbyComparisonEqualToOrLessThan = -2,
		k_ELobbyComparisonLessThan = -1,
		k_ELobbyComparisonEqual = 0,
		k_ELobbyComparisonGreaterThan = 1,
		k_ELobbyComparisonEqualToOrGreaterThan = 2,
	}
	
	public enum ENewsUpdateType
	{
		k_EAppNews = 0,
		k_ESteamAds = 1,
		k_ESteamNews = 2,
		k_ECDDBUpdate = 3,
		k_EClientUpdate = 4,
	}
	
	public enum ELogonState
	{
		k_ELogonStateNotLoggedOn = 0,
		k_ELogonStateLoggingOn = 1,
		k_ELogonStateLoggingOff = 2,
		k_ELogonStateLoggedOn = 3,
	}
	
	public enum ESteamSubscriptionStatus
	{
		eSteamSubscriptionOK = 0,
		eSteamSubscriptionPending = 1,
		eSteamSubscriptionPreorder = 2,
		eSteamSubscriptionPrepurchaseTransferred = 3,
		eSteamSubscriptionPrepurchaseInvalid = 4,
		eSteamSubscriptionPrepurchaseRejected = 5,
		eSteamSubscriptionPrepurchaseRevoked = 6,
		eSteamSubscriptionPaymentCardDeclined = 7,
		eSteamSubscriptionCancelledByUser = 8,
		eSteamSubscriptionCancelledByVendor = 9,
		eSteamSubscriptionPaymentCardUseLimit = 10,
		eSteamSubscriptionPaymentCardAlert = 11,
		eSteamSubscriptionFailed = 12,
		eSteamSubscriptionPaymentCardAVSFailure = 13,
		eSteamSubscriptionPaymentCardInsufficientFunds = 14,
		eSteamSubscriptionRestrictedCountry = 15,
	}
	
	public enum EAvatarSize
	{
		k_EAvatarSize32x32 = 0,
		k_EAvatarSize64x64 = 1,
	}
	
	public enum ECallState
	{
		k_ECallStateUnknown = 0,
		k_ECallStateWaiting = 1,
		k_ECallStateDialing = 2,
		k_ECallStateRinging = 3,
		k_ECallStateInCall = 4,
	}
	
	public enum ESteamFindFilter
	{
		eSteamFindLocalOnly = 0,
		eSteamFindRemoteOnly = 1,
		eSteamFindAll = 2,
	}
	
	public enum ESteamSeekMethod
	{
		eSteamSeekMethodSet = 0,
		eSteamSeekMethodCur = 1,
		eSteamSeekMethodEnd = 2,
	}
	
	public enum EItemQuality
	{
		k_EItemQuality_Normal = 0,
		k_EItemQuality_Common = 1,
		k_EItemQuality_Rare = 2,
		k_EItemQuality_Unique = 3,
		k_EItemQuality_Count = 4,
		k_EItemQuality_Unk5 = 5,
		k_EItemQuality_Unk6 = 6,
		k_EItemQuality_Community = 7,
		k_EItemQuality_Valve = 8,
		k_EItemQuality_Max = 255,
	}
	
	public enum ESteamNotify
	{
		eSteamNotifyTicketsWillExpire = 0,
		eSteamNotifyAccountInfoChanged = 1,
		eSteamNotifyContentDescriptionChanged = 2,
		eSteamNotifyPleaseShutdown = 3,
		eSteamNotifyNewContentServer = 4,
		eSteamNotifySubscriptionStatusChanged = 5,
		eSteamNotifyContentServerConnectionLost = 6,
		eSteamNotifyCacheLoadingCompleted = 7,
		eSteamNotifyCacheNeedsDecryption = 8,
		eSteamNotifyCacheNeedsRepair = 9,
		eSteamNotifyAppDownloading = 10,
		eSteamNotifyAppDownloadingPaused = 11,
	}
	
	public enum EChatEntryType
	{
		k_EChatEntryTypeChatMsg = 1,
		k_EChatEntryTypeTyping = 2,
		k_EChatEntryTypeInviteGame = 3,
		k_EChatEntryTypeEmote = 4,
		k_EChatEntryTypeLobbyGameStart = 5,
	}
	
	public enum ECallbackType
	{
		k_iSteamUserCallbacks = 100,
		k_iSteamGameServerCallbacks = 200,
		k_iSteamFriendsCallbacks = 300,
		k_iSteamBillingCallbacks = 400,
		k_iSteamMatchmakingCallbacks = 500,
		k_iSteamContentServerCallbacks = 600,
		k_iSteamUtilsCallbacks = 700,
		k_iClientFriendsCallbacks = 800,
		k_iClientUserCallbacks = 900,
		k_iSteamAppsCallbacks = 1000,
		k_iSteamUserStatsCallbacks = 1100,
		k_iSteamNetworkingCallbacks = 1200,
		k_iClientRemoteStorageCallbacks = 1300,
		k_iSteamUserItemsCallbacks = 1400,
		k_iSteamGameServerItemsCallbacks = 1500,
		k_iClientUtilsCallbacks = 1600,
		k_iSteamGameCoordinatorCallbacks = 1700,
	}
	
	public enum EVACBan
	{
		k_EVACBanGoldsrc = 0,
		k_EVACBanSource = 1,
		k_EVACBanDayOfDefeatSource = 2,
	}
	
	public enum EClanRank
	{
		k_EClanRankNone = 0,
		k_EClanRankOwner = 1,
		k_EClanRankOfficer = 2,
		k_EClanRankMember = 3,
	}
	
	public enum EItemCriteriaOperator
	{
		k_EOperator_String_EQ = 0,
		k_EOperator_Not = 1,
		k_EOperator_String_Not_EQ = 1,
		k_EOperator_Float_EQ = 2,
		k_EOperator_Float_Not_EQ = 3,
		k_EOperator_Float_LT = 4,
		k_EOperator_Float_Not_LT = 5,
		k_EOperator_Float_LTE = 6,
		k_EOperator_Float_Not_LTE = 7,
		k_EOperator_Float_GT = 8,
		k_EOperator_Float_Not_GT = 9,
		k_EOperator_Float_GTE = 10,
		k_EOperator_Float_Not_GTE = 11,
		k_EOperator_Subkey_Contains = 12,
		k_EOperator_Subkey_Not_Contains = 13,
		k_EItemCriteriaOperator_Count = 14,
	}
	
	public enum EChatRoomVoiceStatus
	{
		eChatRoomVoiceStatusBad = 0,
		eChatRoomVoiceStatusUnknownRoom = 1,
		eChatRoomVoiceStatusUnknownUser = 2,
		eChatRoomVoiceStatusNotSpeaking = 3,
		eChatRoomVoiceStatusConnectedSpeaking = 4,
		eChatRoomVoiceStatusConnectedSpeakingData = 5,
		eChatRoomVoiceStatusNotConnectedSpeaking = 6,
		eChatRoomVoiceStatusConnecting = 7,
		eChatRoomVoiceStatusUnreachable = 8,
		eChatRoomVoiceStatusDisconnected = 9,
		eChatRoomVoiceStatusCount = 10,
	}
	
	public enum EGCMessages
	{
		k_ESOMsg_Create = 21,
		k_ESOMsg_Update = 22,
		k_ESOMsg_Destroy = 23,
		k_ESOMsg_CacheSubscribed = 24,
		k_ESOMsg_CacheUnsubscribed = 25,
		k_EGCMsgStartPlaying = 53,
		k_EGCMsgStopPlaying = 54,
		k_EGCMsgStartGameserver = 55,
		k_EGCMsgStopGameserver = 56,
		k_EMsgGCSetItemPosition = 1001,
		k_EMsgGCCraft = 1002,
		k_EMsgGCCraftResponse = 1003,
		k_EMsgGCDelete = 1004,
		k_EMsgGCDev_NewItemRequest = 2001,
		k_EMsgGCDev_NewItemRequestResponse = 2002,
	}
	
	public enum EPaymentMethod
	{
		k_EPaymentMethodNone = 0,
		k_EPaymentMethodCDKey = 1,
		k_EPaymentMethodCreditCard = 2,
		k_EPaymentMethodPayPal = 4,
		k_EPaymentMethodManual = 8,
	}
	
	public enum EPersonaState
	{
		k_EPersonaStateOffline = 0,
		k_EPersonaStateOnline = 1,
		k_EPersonaStateBusy = 2,
		k_EPersonaStateAway = 3,
		k_EPersonaStateSnooze = 4,
		k_EPersonaStateMax = 5,
	}
	
	public enum ESteamAppUpdateStatsQueryType
	{
		ePhysicalBytesReceivedThisSession = 1,
		eAppReadyToLaunchStatus = 2,
		eAppPreloadStatus = 3,
		eAppEntireDepot = 4,
		eCacheBytesPresent = 5,
	}
	
	public enum ELeaderboardDataRequest
	{
		k_ELeaderboardDataRequestGlobal = 0,
		k_ELeaderboardDataRequestGlobalAroundUser = 1,
		k_ELeaderboardDataRequestFriends = 2,
	}
	
	public enum EConnectionPriority
	{
		k_EConnectionPriorityLow = 0,
		k_EConnectionPriorityMedium = 1,
		k_EConnectionPriorityHigh = 2,
	}
	
	public enum EAuthSessionResponse
	{
		k_EAuthSessionResponseOK = 0,
		k_EAuthSessionResponseUserNotConnectedToSteam = 1,
		k_EAuthSessionResponseNoLicenseOrExpired = 2,
		k_EAuthSessionResponseVACBanned = 3,
		k_EAuthSessionResponseLoggedInElseWhere = 4,
		k_EAuthSessionResponseVACCheckTimedOut = 5,
		k_EAuthSessionResponseAuthTicketCanceled = 6,
		k_EAuthSessionResponseAuthTicketInvalidAlreadyUsed = 7,
		k_EAuthSessionResponseAuthTicketInvalid = 8,
	}
	
	public enum EItemRequestResult
	{
		k_EItemRequestResultOK = 0,
		k_EItemRequestResultDenied = 1,
		k_EItemRequestResultServerError = 2,
		k_EItemRequestResultTimeout = 3,
		k_EItemRequestResultInvalid = 4,
		k_EItemRequestResultNoMatch = 5,
		k_EItemRequestResultUnknownError = 6,
		k_EItemRequestResultNotLoggedOn = 7,
	}
	
	public enum EClanRelationship
	{
		eClanRelationshipNone = 0,
		eClanRelationshipBlocked = 1,
		eClanRelationshipInvited = 2,
		eClanRelationshipMember = 3,
		eClanRelationshipKicked = 4,
	}
	
	public enum EResult
	{
		k_EResultOK = 1,
		k_EResultFail = 2,
		k_EResultNoConnection = 3,
		k_EResultInvalidPassword = 5,
		k_EResultLoggedInElsewhere = 6,
		k_EResultInvalidProtocolVer = 7,
		k_EResultInvalidParam = 8,
		k_EResultFileNotFound = 9,
		k_EResultBusy = 10,
		k_EResultInvalidState = 11,
		k_EResultInvalidName = 12,
		k_EResultInvalidEmail = 13,
		k_EResultDuplicateName = 14,
		k_EResultAccessDenied = 15,
		k_EResultTimeout = 16,
		k_EResultBanned = 17,
		k_EResultAccountNotFound = 18,
		k_EResultInvalidSteamID = 19,
		k_EResultServiceUnavailable = 20,
		k_EResultNotLoggedOn = 21,
		k_EResultPending = 22,
		k_EResultEncryptionFailure = 23,
		k_EResultInsufficientPrivilege = 24,
		k_EResultLimitExceeded = 25,
		k_EResultRevoked = 26,
		k_EResultExpired = 27,
		k_EResultAlreadyRedeemed = 28,
		k_EResultDuplicateRequest = 29,
		k_EResultAlreadyOwned = 30,
		k_EResultIPNotFound = 31,
		k_EResultPersistFailed = 32,
		k_EResultLockingFailed = 33,
		k_EResultLogonSessionReplaced = 34,
		k_EResultConnectFailed = 35,
		k_EResultHandshakeFailed = 36,
		k_EResultIOFailure = 37,
		k_EResultRemoteDisconnect = 38,
		k_EResultShoppingCartNotFound = 39,
		k_EResultBlocked = 40,
		k_EResultIgnored = 41,
		k_EResultNoMatch = 42,
		k_EResultAccountDisabled = 43,
		k_EResultServiceReadOnly = 44,
	}
	
	public enum EPersonaChange
	{
		k_EPersonaChangeName = 1,
		k_EPersonaChangeStatus = 2,
		k_EPersonaChangeComeOnline = 4,
		k_EPersonaChangeGoneOffline = 8,
		k_EPersonaChangeGamePlayed = 16,
		k_EPersonaChangeGameServer = 32,
		k_EPersonaChangeAvatar = 64,
		k_EPersonaChangeJoinedSource = 128,
		k_EPersonaChangeLeftSource = 256,
		k_EPersonaChangeRelationshipChanged = 512,
		k_EPersonaChangeNameFirstSet = 1024,
	}
	
	public enum EDetailedPlatformErrorType
	{
		eNoDetailedErrorAvailable = 0,
		eStandardCerrno = 1,
		eWin32LastError = 2,
		eWinSockLastError = 3,
		eDetailedPlatformErrorCount = 4,
	}
	
	public enum EVoiceResult
	{
		k_EVoiceResultOK = 0,
		k_EVoiceResultNotInitialized = 1,
		k_EVoiceResultNotRecording = 2,
		k_EVoiceResultNoData = 3,
		k_EVoiceResultBufferTooSmall = 4,
		k_EVoiceResultDataCorrupted = 5,
	}
	
	public enum ESteamError
	{
		eSteamErrorNone = 0,
		eSteamErrorUnknown = 1,
		eSteamErrorLibraryNotInitialized = 2,
		eSteamErrorLibraryAlreadyInitialized = 3,
		eSteamErrorConfig = 4,
		eSteamErrorContentServerConnect = 5,
		eSteamErrorBadHandle = 6,
		eSteamErrorHandlesExhausted = 7,
		eSteamErrorBadArg = 8,
		eSteamErrorNotFound = 9,
		eSteamErrorRead = 10,
		eSteamErrorEOF = 11,
		eSteamErrorSeek = 12,
		eSteamErrorCannotWriteNonUserConfigFile = 13,
		eSteamErrorCacheOpen = 14,
		eSteamErrorCacheRead = 15,
		eSteamErrorCacheCorrupted = 16,
		eSteamErrorCacheWrite = 17,
		eSteamErrorCacheSession = 18,
		eSteamErrorCacheInternal = 19,
		eSteamErrorCacheBadApp = 20,
		eSteamErrorCacheVersion = 21,
		eSteamErrorCacheBadFingerPrint = 22,
		eSteamErrorNotFinishedProcessing = 23,
		eSteamErrorNothingToDo = 24,
		eSteamErrorCorruptEncryptedUserIDTicket = 25,
		eSteamErrorSocketLibraryNotInitialized = 26,
		eSteamErrorFailedToConnectToUserIDTicketValidationServer = 27,
		eSteamErrorBadProtocolVersion = 28,
		eSteamErrorReplayedUserIDTicketFromClient = 29,
		eSteamErrorReceiveResultBufferTooSmall = 30,
		eSteamErrorSendFailed = 31,
		eSteamErrorReceiveFailed = 32,
		eSteamErrorReplayedReplyFromUserIDTicketValidationServer = 33,
		eSteamErrorBadSignatureFromUserIDTicketValidationServer = 34,
		eSteamErrorValidationStalledSoAborted = 35,
		eSteamErrorInvalidUserIDTicket = 36,
		eSteamErrorClientLoginRateTooHigh = 37,
		eSteamErrorClientWasNeverValidated = 38,
		eSteamErrorInternalSendBufferTooSmall = 39,
		eSteamErrorInternalReceiveBufferTooSmall = 40,
		eSteamErrorUserTicketExpired = 41,
		eSteamErrorCDKeyAlreadyInUseOnAnotherClient = 42,
		eSteamErrorNotLoggedIn = 101,
		eSteamErrorAlreadyExists = 102,
		eSteamErrorAlreadySubscribed = 103,
		eSteamErrorNotSubscribed = 104,
		eSteamErrorAccessDenied = 105,
		eSteamErrorFailedToCreateCacheFile = 106,
		eSteamErrorCallStalledSoAborted = 107,
		eSteamErrorEngineNotRunning = 108,
		eSteamErrorEngineConnectionLost = 109,
		eSteamErrorLoginFailed = 110,
		eSteamErrorAccountPending = 111,
		eSteamErrorCacheWasMissingRetry = 112,
		eSteamErrorLocalTimeIncorrect = 113,
		eSteamErrorCacheNeedsDecryption = 114,
		eSteamErrorAccountDisabled = 115,
		eSteamErrorCacheNeedsRepair = 116,
		eSteamErrorRebootRequired = 117,
		eSteamErrorNetwork = 200,
		eSteamErrorOffline = 201,
	}
	
	public enum EMatchMakingType
	{
		eInternetServer = 0,
		eLANServer = 1,
		eFriendsServer = 2,
		eFavoritesServer = 3,
		eHistoryServer = 4,
		eSpectatorServer = 5,
		eInvalidServer = 6,
	}
	
	public enum EChatRoomEnterResponse
	{
		k_EChatRoomEnterResponseSuccess = 1,
		k_EChatRoomEnterResponseDoesntExist = 2,
		k_EChatRoomEnterResponseNotAllowed = 3,
		k_EChatRoomEnterResponseFull = 4,
		k_EChatRoomEnterResponseError = 5,
		k_EChatRoomEnterResponseBanned = 6,
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=272)]
	public struct GCSetItemPosition_t
	{
		public UInt16 id;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 16)]
		public SByte[] garbage;
		public UInt64 itemID;
		public UInt32 position;
		public UInt32 unk1;
		const int k_iMessage = 1001;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=96)]
	public struct ClientAppNewsItemUpdate_t
	{
		public Byte m_eNewsUpdateType;
		public UInt32 m_uNewsID;
		public UInt32 m_uAppID;
		const int k_iCallback = 110;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=64)]
	public struct SteamIDComponent_t
	{
		public UInt32 m_unAccountID;
		public UInt32 m_unAccountInstance;
		public UInt32 m_EAccountType;
		public EUniverse m_EUniverse;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=64)]
	public class CSteamID
	{

		[StructLayout(LayoutKind.Explicit,CharSet=CharSet.Ansi,Pack=1,Size=64)]
		struct SteamID_t
		{
			[FieldOffset(0)]
			public SteamIDComponent_t m_comp;
			[FieldOffset(0)]
			public UInt64 m_unAll64Bits;
		}
		
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=160)]
	public struct SocketStatusCallback_t
	{
		public UInt32 m_hSocket;
		public UInt32 m_hListenSocket;
		public CSteamID m_steamIDRemote;
		public Int32 m_eSNetSocketState;
		const int k_iCallback = 1201;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct GSItemGranted_t
	{
		public CSteamID m_steamID;
		public UInt64 m_itemID;
		const int k_iCallback = 1507;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=208)]
	public struct SOMsgCacheUnsubscribed_t
	{
		public UInt16 id;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 16)]
		public SByte[] garbage;
		public CSteamID steamid;
		const int k_iMessage = 25;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=8)]
	public struct GSPolicyResponse_t
	{
		public Byte m_bSecure;
		const int k_iCallback = 115;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=64)]
	public struct PurchaseMsg_t
	{
		public UInt32 m_bSuccess;
		public EPurchaseResultDetail m_EPurchaseResultDetail;
		const int k_iCallback = 402;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=448)]
	public struct SOMsgCreate_t
	{
		public UInt16 id;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 16)]
		public SByte[] garbage;
		public CSteamID steamid;
		public UInt32 unknown;
		public UInt64 itemid;
		public UInt32 accountid;
		public UInt16 itemtype;
		public Byte itemlevel;
		public Byte itemquality;
		public UInt32 position;
		public UInt32 itemcount;
		public UInt16 attribcount;
		const int k_iMessage = 21;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=96)]
	public struct GSClientKick_t
	{
		public CSteamID m_SteamID;
		public EDenyReason m_eDenyReason;
		const int k_iCallback = 203;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct UserItemDeleted_t
	{
		public UInt64 m_itemID;
		public UInt32 Unk0;
		public UInt32 Unk1;
		const int k_iCallback = 1402;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=192)]
	public struct PersonaStateChangeOld_t
	{
		public UInt64 m_ulSteamID;
		public Int32 m_ePersonaStatePrevious;
		public Int32 m_nGameIDPrevious;
		public UInt32 m_unGameServerIPPrevious;
		public UInt16 m_usGameServerPortPrevious;
		const int k_iCallback = 303;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=1120)]
	public struct GSClientDeny_t
	{
		public CSteamID m_SteamID;
		public EDenyReason m_eDenyReason;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 128)]
		public SByte[] m_pchOptionalText;
		const int k_iCallback = 202;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=288)]
	public struct GCCraftResponse_t
	{
		public UInt16 id;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 16)]
		public SByte[] garbage;
		public UInt16 blueprint;
		public UInt64 unk1;
		public UInt64 itemid;
		const int k_iMessage = 1003;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=64)]
	public struct AppDataChanged_t
	{
		public UInt32 m_Sequence;
		public UInt32 m_Unknown;
		const int k_iCallback = 1001;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct LobbyDataUpdate_t
	{
		public UInt64 m_ulSteamIDLobby;
		public UInt64 m_ulSteamIDMember;
		const int k_iCallback = 505;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=1024)]
	public struct GameServerChangeRequested_t
	{
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 64)]
		public SByte[] m_rgchServer;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 64)]
		public SByte[] m_rgchPassword;
		const int k_iCallback = 332;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=160)]
	public struct FinalPriceMsg_t
	{
		public UInt32 m_bSuccess;
		public UInt32 m_nBaseCost;
		public UInt32 m_nTotalDiscount;
		public UInt32 m_nTax;
		public UInt32 m_nShippingCost;
		const int k_iCallback = 401;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=192)]
	public struct LobbyGameCreated_t
	{
		public UInt64 m_ulSteamIDLobby;
		public UInt64 m_ulSteamIDGameServer;
		public UInt32 m_unIP;
		public UInt16 m_usPort;
		const int k_iCallback = 509;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=64)]
	public struct GameID_t
	{
		public UInt32 m_nAppID;
		public UInt32 m_nType;
		public UInt32 m_nModID;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=64)]
	public class CGameID
	{

		[StructLayout(LayoutKind.Explicit,CharSet=CharSet.Ansi,Pack=1,Size=64)]
		struct Union
		{
			[FieldOffset(0)]
			public UInt64 m_ulGameID;
			[FieldOffset(0)]
			public GameID_t m_gameID;
		}
		
		const int k_EGameIDTypeApp = 0;
		const int k_EGameIDTypeGameMod = 1;
		const int k_EGameIDTypeShortcut = 2;
		const int k_EGameIDTypeP2P = 3;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=8)]
	public struct SteamShutdown_t
	{
		const int k_iCallback = 704;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=272)]
	public struct SOMsgCacheSubscribed_t
	{
		public UInt16 id;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 16)]
		public SByte[] garbage;
		public CSteamID steamid;
		public UInt32 unknown;
		public UInt16 padding;
		public UInt16 itemcount;
		const int k_iMessage = 24;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=96)]
	public struct ClientSteamNewsClientUpdate_t
	{
		public Byte m_eNewsUpdateType;
		public Byte m_bReloadCDDB;
		public UInt32 m_unCurrentBootstrapperVersion;
		public UInt32 m_unCurrentClientVersion;
		const int k_iCallback = 116;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=64)]
	public struct GSClientApprove_t
	{
		public CSteamID m_SteamID;
		const int k_iCallback = 201;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct GSGameplayStats_t
	{
		public EResult m_eResult;
		public Int32 m_nRank;
		public UInt32 m_unTotalConnects;
		public UInt32 m_unTotalMinutesPlayed;
		const int k_iCallback = 207;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=256)]
	public struct LobbyChatUpdate_t
	{
		public UInt64 m_ulSteamIDLobby;
		public UInt64 m_ulSteamIDUserChanged;
		public UInt64 m_ulSteamIDMakingChange;
		public UInt32 m_rgfChatMemberStateChange;
		const int k_iCallback = 506;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=8)]
	public struct PrimaryChatDestinationSet_t
	{
		public Byte m_bIsPrimary;
		const int k_iCallback = 114;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=1216)]
	public struct UserAchievementStored_t
	{
		public UInt64 m_nGameID;
		public bool m_bGroupAchievement;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 128)]
		public SByte[] m_rgchAchievementName;
		public UInt32 m_nCurProgress;
		public UInt32 m_nMaxProgress;
		const int k_iCallback = 1103;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=1152)]
	public struct GSClientAchievementStatus_t
	{
		public UInt64 m_SteamID;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 128)]
		public SByte[] m_pchAchievement;
		public bool m_bUnlocked;
		const int k_iCallback = 206;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=304)]
	public struct SOMsgDeleted_t
	{
		public UInt16 id;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 16)]
		public SByte[] garbage;
		public CSteamID steamid;
		public UInt32 unk1;
		public UInt64 itemid;
		const int k_iMessage = 23;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=96)]
	public struct ValidateAuthTicketResponse_t
	{
		public CSteamID m_SteamID;
		public EAuthSessionResponse m_eAuthSessionResponse;
		const int k_iCallback = 143;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=8)]
	public struct BeginLogonRetry_t
	{
		const int k_iCallback = 104;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct GSClientSteam2Accept_t
	{
		public UInt32 m_UserID;
		public UInt64 m_SteamID;
		const int k_iCallback = 205;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=96)]
	public class CCallbackBase
	{
		public Byte m_nCallbackFlags;
		public Int32 m_iCallback;
		const int k_ECallbackFlagsRegistered = 1;
		const int k_ECallbackFlagsGameServer = 2;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct LobbyInvite_t
	{
		public UInt64 m_ulSteamIDUser;
		public UInt64 m_ulSteamIDLobby;
		const int k_iCallback = 503;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=192)]
	public struct GSItemRequest_t
	{
		public CSteamID m_steamID;
		public EItemRequestResult m_eResult;
		public UInt64 m_itemID;
		const int k_iCallback = 1501;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=64)]
	public struct LobbyClosing_t
	{
		public UInt64 m_ulSteamIDLobby;
		const int k_iCallback = 511;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=176)]
	public struct GCCraft_t
	{
		public UInt16 id;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 16)]
		public SByte[] garbage;
		public UInt16 blueprint;
		public UInt16 itemcount;
		const int k_iMessage = 1002;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public struct SteamServerConnectFailure_t
	{
		public EResult m_eResult;
		const int k_iCallback = 102;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=64)]
	public struct FriendEndChatSession_t
	{
		public CSteamID m_SteamID;
		const int k_iCallback = 312;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public struct LogonFailure_t
	{
		public EResult m_eResult;
		const int k_iCallback = 102;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=8)]
	public struct LowBatteryPower_t
	{
		public Byte m_nMinutesBatteryLeft;
		const int k_iCallback = 702;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=192)]
	public struct LobbyEnter_t
	{
		public UInt64 m_ulSteamIDLobby;
		public UInt32 m_rgfChatPermissions;
		public bool m_bLocked;
		public EChatRoomEnterResponse m_EChatRoomEnterResponse;
		const int k_iCallback = 504;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct GameLobbyJoinRequested_t
	{
		public CSteamID m_steamIDLobby;
		public CSteamID m_steamIDFriend;
		const int k_iCallback = 333;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public struct SteamServersDisconnected_t
	{
		public EResult m_eResult;
		const int k_iCallback = 103;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=64)]
	public struct GSClientSteam2Deny_t
	{
		public UInt32 m_UserID;
		public UInt32 m_eSteamError;
		const int k_iCallback = 204;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=256)]
	public struct ClientSteamNewsItemUpdate_t
	{
		public Byte m_eNewsUpdateType;
		public UInt32 m_uNewsID;
		public UInt32 m_uHaveSubID;
		public UInt32 m_uNotHaveSubID;
		public UInt32 m_uHaveAppID;
		public UInt32 m_uNotHaveAppID;
		public UInt32 m_uHaveAppIDInstalled;
		public UInt32 m_uHavePlayedAppID;
		const int k_iCallback = 112;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=64)]
	public struct SteamAPICallCompleted_t
	{
		public UInt64 m_hAsyncCall;
		const int k_iCallback = 703;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=8)]
	public struct CallbackPipeFailure_t
	{
		const int k_iCallback = 117;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=192)]
	public struct LeaderboardScoresDownloaded_t
	{
		public UInt64 m_hSteamLeaderboard;
		public UInt64 m_hSteamLeaderboardEntries;
		public Int32 m_cEntryCount;
		const int k_iCallback = 1105;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=64)]
	public struct UserRequestingFriendship_t
	{
		public UInt64 m_ulSteamID;
		const int k_iCallback = 302;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=192)]
	public struct FavoritesListChanged_t
	{
		public UInt32 m_nIP;
		public UInt32 m_nQueryPort;
		public UInt32 m_nConnPort;
		public UInt32 m_nAppID;
		public UInt32 m_nFlags;
		public bool m_bAdd;
		const int k_iCallback = 502;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=8288)]
	public struct GSItemGetBlob_t
	{
		public UInt64 m_itemID;
		public EItemRequestResult m_eResult;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 1024)]
		public Byte[] m_itemBlob;
		const int k_iCallback = 1508;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct GSItemCount_t
	{
		public CSteamID m_steamID;
		public EItemRequestResult m_eResult;
		public UInt32 m_unCount;
		const int k_iCallback = 1500;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=208)]
	public struct GCDelete_t
	{
		public UInt16 id;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 16)]
		public SByte[] garbage;
		public UInt64 itemID;
		const int k_iMessage = 1004;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=144)]
	public struct GSClientGroupStatus_t
	{
		public CSteamID m_SteamIDUser;
		public CSteamID m_SteamIDGroup;
		public bool m_bMember;
		public bool m_bOfficer;
		const int k_iCallback = 208;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=8)]
	public struct IPCFailure_t
	{
		public Byte m_eFailureType;
		const int k_iCallback = 117;
		const int k_EFailureFlushedCallbackQueue = 0;
		const int k_EFailurePipeFail = 1;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct LobbyKicked_t
	{
		public UInt64 m_ulSteamIDLobby;
		public UInt64 m_ulSteamIDAdmin;
		const int k_iCallback = 512;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32800)]
	public struct SystemIM_t
	{
		public UInt32 m_ESystemIMType;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 4096)]
		public SByte[] m_rgchMsgBody;
		const int k_iCallback = 305;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=192)]
	public struct LobbyChatMsg_t
	{
		public UInt64 m_ulSteamIDLobby;
		public UInt64 m_ulSteamIDUser;
		public EChatEntryType m_eChatEntryType;
		public UInt32 m_iChatID;
		const int k_iCallback = 507;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct UserItemGranted_t
	{
		public UInt64 m_itemID;
		public CGameID m_gameID;
		const int k_iCallback = 1403;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct UserItemSetBlob_t
	{
		public UInt64 m_itemID;
		public EItemRequestResult m_eResult;
		public UInt32 Unk;
		const int k_iCallback = 1405;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct LeaderboardFindResult_t
	{
		public UInt64 m_hSteamLeaderboard;
		public Byte m_bLeaderboardFound;
		const int k_iCallback = 1104;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct UserStatsStored_t
	{
		public UInt64 m_nGameID;
		public EResult m_eResult;
		const int k_iCallback = 1102;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct ClientGameServerDeny_t
	{
		public UInt32 m_uAppID;
		public UInt32 m_unGameServerIP;
		public UInt16 m_usGameServerPort;
		public UInt16 m_bSecure;
		public UInt32 m_uReason;
		const int k_iCallback = 113;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=8)]
	public struct IPCountry_t
	{
		const int k_iCallback = 701;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=192)]
	public struct FriendChatMsg_t
	{
		public UInt64 m_ulReceiver;
		public UInt64 m_ulSender;
		public UInt32 m_iUnknown1;
		public UInt32 m_iChatID;
		const int k_iCallback = 306;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=256)]
	public struct LeaderboardScoreUploaded_t
	{
		public Byte m_bSuccess;
		public UInt64 m_hSteamLeaderboard;
		public Int32 m_nScore;
		public Byte m_bScoreChanged;
		public Int32 m_nGlobalRankNew;
		public Int32 m_nGlobalRankPrevious;
		const int k_iCallback = 1106;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct LobbyCreated_t
	{
		public EResult m_eResult;
		public UInt64 m_ulSteamIDLobby;
		const int k_iCallback = 513;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public struct LoggedOff_t
	{
		public EResult m_eResult;
		const int k_iCallback = 103;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=8)]
	public struct SteamServersConnected_t
	{
		const int k_iCallback = 101;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct LobbyAdminChange_t
	{
		public UInt64 m_ulSteamIDLobby;
		public UInt64 m_ulSteamIDNewAdmin;
		const int k_iCallback = 508;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=8)]
	public struct Steam2TicketChanged_t
	{
		const int k_iCallback = 106;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public struct LobbyMatchList_t
	{
		public UInt32 m_nLobbiesMatching;
		const int k_iCallback = 510;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=8288)]
	public struct UserItemGetBlob_t
	{
		public UInt64 m_itemID;
		public EItemRequestResult m_eResult;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 1024)]
		public Byte[] itemBlob;
		const int k_iCallback = 1404;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=8)]
	public struct GameOverlayActivated_t
	{
		public Byte m_bActive;
		const int k_iCallback = 331;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public struct GameCoordinatorMessageAvailable_t
	{
		public UInt32 messageLength;
		const int k_iCallback = 1701;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct UserItemMoved_t
	{
		public UInt64 m_itemID;
		public UInt32 Unk0;
		public UInt32 Unk1;
		const int k_iCallback = 1401;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct PersonaStateChange_t
	{
		public UInt64 m_ulSteamID;
		public Int32 m_nChangeFlags;
		const int k_iCallback = 304;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct UserItemCount_t
	{
		public CGameID m_gameID;
		public EItemRequestResult m_eResult;
		public UInt32 m_unCount;
		const int k_iCallback = 1400;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=352)]
	public struct SOMsgUpdate_t
	{
		public UInt16 id;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 16)]
		public SByte[] garbage;
		public CSteamID steamid;
		public UInt32 unk1;
		public UInt64 itemID;
		public UInt16 unk2;
		public UInt32 position;
		const int k_iMessage = 22;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=8)]
	public struct LogonSuccess_t
	{
		const int k_iCallback = 101;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=192)]
	public struct UserStatsReceived_t
	{
		public UInt64 m_nGameID;
		public EResult m_eResult;
		public CSteamID m_steamIDUser;
		const int k_iCallback = 1101;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=8)]
	public struct UserPolicyResponse_t
	{
		public Byte m_bSecure;
		const int k_iCallback = 115;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public struct DlcInstalled_t
	{
		public UInt32 m_nAppID;
		const int k_iCallback = 1005;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct GSItemSetBlob_t
	{
		public UInt64 m_itemID;
		public EItemRequestResult m_eResult;
		public UInt32 Unk;
		const int k_iCallback = 1509;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct FriendAdded_t
	{
		public Byte m_bSuccess;
		public UInt64 m_ulSteamID;
		const int k_iCallback = 301;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct IClientRemoteStorage
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=320)]
	public struct TSteamAppStats
	{
		public UInt32 uNumApps;
		public UInt32 uMaxNameChars;
		public UInt32 uMaxInstallDirNameChars;
		public UInt32 uMaxVersionLabelChars;
		public UInt32 uMaxLaunchOptions;
		public UInt32 uMaxLaunchOptionDescChars;
		public UInt32 uMaxLaunchOptionCmdLineChars;
		public UInt32 uMaxNumIcons;
		public UInt32 uMaxIconSize;
		public UInt32 uMaxDependencies;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=2112)]
	public struct TSteamProgress
	{
		public Int32 bValid;
		public UInt32 uPercentDone;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 255)]
		public SByte[] szProgress;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=9440)]
	public struct TSteamPaymentCardInfo
	{
		public ESteamPaymentCardType eCardType;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 18)]
		public SByte[] szCardNumber;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 101)]
		public SByte[] szCardHolderName;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 5)]
		public SByte[] szCardExpYear;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 3)]
		public SByte[] szCardExpMonth;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 6)]
		public SByte[] szCardCVV2;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 129)]
		public SByte[] szBillingAddress1;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 129)]
		public SByte[] szBillingAddress2;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 51)]
		public SByte[] szBillingCity;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 17)]
		public SByte[] szBillingZip;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 33)]
		public SByte[] szBillingState;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 33)]
		public SByte[] szBillingCountry;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 21)]
		public SByte[] szBillingPhone;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 101)]
		public SByte[] szBillingEmailAddress;
		public UInt32 uExpectedCostInCents;
		public UInt32 uExpectedTaxInCents;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 101)]
		public SByte[] szShippingName;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 129)]
		public SByte[] szShippingAddress1;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 129)]
		public SByte[] szShippingAddress2;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 51)]
		public SByte[] szShippingCity;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 17)]
		public SByte[] szShippingZip;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 33)]
		public SByte[] szShippingState;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 33)]
		public SByte[] szShippingCountry;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 21)]
		public SByte[] szShippingPhone;
		public UInt32 uExpectedShippingCostInCents;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct ISteamUser
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct ISteamMatchmakingServers
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=192)]
	public struct FriendGameInfo_t
	{
		public CGameID m_gameID;
		public UInt32 m_unGameIP;
		public UInt16 m_usGamePort;
		public UInt16 m_usQueryPort;
		public CSteamID m_steamIDLobby;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=2112)]
	public struct TSteamAppDependencyInfo
	{
		public UInt32 AppId;
		public UInt32 IsRequired;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 255)]
		public SByte[] szMountName;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=2240)]
	public struct TSteamElemInfo
	{
		public Int32 bIsDir;
		public UInt32 uSizeOrCount;
		public Int32 bIsLocal;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 255)]
		public SByte[] cszName;
		public Int32 lLastAccessTime;
		public Int32 lLastModificationTime;
		public Int32 lCreationTime;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct IClientNetworking
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=1456)]
	public struct TSteamExternalBillingInfo
	{
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 101)]
		public SByte[] szAccountName;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 81)]
		public SByte[] szPassword;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=1856)]
	public struct TSteamPrepurchaseInfo
	{
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 21)]
		public SByte[] szTypeOfProofOfPurchase;
		public UInt32 uLengthOfBinaryProofOfPurchaseToken;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 201)]
		public SByte[] cBinaryProofOfPurchaseToken;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=9472)]
	public struct TSteamSubscriptionBillingInfo
	{
		public ESteamSubscriptionBillingInfoType eBillingInfoType;

		[StructLayout(LayoutKind.Explicit,CharSet=CharSet.Ansi,Pack=1,Size=9440)]
		struct Union
		{
			[FieldOffset(0)]
			public TSteamPaymentCardInfo PaymentCardInfo;
			[FieldOffset(0)]
			public TSteamPrepurchaseInfo PrepurchaseInfo;
			[FieldOffset(0)]
			public TSteamExternalBillingInfo ExternalBillingInfo;
			[FieldOffset(0)]
			public SByte bUseAccountBillingInfo;
		}
		
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=2144)]
	public struct TSTeamError
	{
		public ESteamError eSteamError;
		public EDetailedPlatformErrorType eDetailedErrorType;
		public Int32 nDetailedErrorCode;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 255)]
		public SByte[] szDesc;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct CCallbackMgr
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct CallbackMsg_t
	{
		public Int32 m_hSteamUser;
		public Int32 m_iCallback;
		public IntPtr m_pubParam;
		public Int32 m_cubParam;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=576)]
	public struct TSteamApp
	{
		public IntPtr szName;
		public UInt32 uMaxNameChars;
		public IntPtr szLatestVersionLabel;
		public UInt32 uMaxLatestVersionLabelChars;
		public IntPtr szCurrentVersionLabel;
		public UInt32 uMaxCurrentVersionLabelChars;
		public IntPtr szInstallDirName;
		public UInt32 uMaxInstallDirNameChars;
		public UInt32 uId;
		public UInt32 uLatestVersionId;
		public UInt32 uCurrentVersionId;
		public UInt32 uMinCacheFileSizeMB;
		public UInt32 uMaxCacheFileSizeMB;
		public UInt32 uNumLaunchOptions;
		public UInt32 uNumIcons;
		public UInt32 uNumVersions;
		public UInt32 uNumDependencies;
		public IntPtr szUnkString;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct ConnectedUserInfo_t
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct ISteamApps
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=96)]
	public struct TSteamSubscriptionStats
	{
		public UInt32 uNumSubscriptions;
		public UInt32 uMaxNameChars;
		public UInt32 uMaxApps;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct ISteamFriends
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=2112)]
	public struct TSteamDiscountQualifier
	{
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 255)]
		public SByte[] szName;
		public UInt32 uRequiredSubscription;
		public Int32 bIsDisqualifier;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct TSteamUpdateStats
	{
		public UInt64 uBytesTotal;
		public UInt64 uBytesPresent;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=168)]
	public struct TSteamPrepurchaseReceiptInfo
	{
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 21)]
		public SByte[] szTypeOfProofOfPurchase;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct ISteamContentServer
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public struct castable_string_t
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=5088)]
	public struct TSteamPaymentCardReceiptInfo
	{
		public ESteamPaymentCardType eCardType;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 5)]
		public SByte[] szCardLastFourDigits;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 101)]
		public SByte[] szCardHolderName;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 129)]
		public SByte[] szBillingAddress1;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 129)]
		public SByte[] szBillingAddress2;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 51)]
		public SByte[] szBillingCity;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 17)]
		public SByte[] szBillingZip;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 33)]
		public SByte[] szBillingState;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 33)]
		public SByte[] szBillingCountry;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 101)]
		public SByte[] szCardApprovalCode;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 10)]
		public SByte[] szTransDate;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 10)]
		public SByte[] szTransTime;
		public UInt32 uPriceWithoutTax;
		public UInt32 uTaxAmount;
		public UInt32 uShippingCost;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct IClientUserStats
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct ISteamGameServer
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct ISteamUserStats
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct ISteamMatchmaking
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct IClientGameServerItems
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public struct string_t
	{
		public IntPtr pszValue;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct TSteamAppVersion
	{
		public IntPtr szLabel;
		public UInt32 uMaxLabelChars;
		public UInt32 uVersionId;
		public Int32 bIsNotAvailable;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=4096)]
	public struct MatchMakingKeyValuePair_t
	{
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 256)]
		public SByte[] m_szKey;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 256)]
		public SByte[] m_szValue;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=64)]
	public struct TSteamSplitLocalUserID
	{
		public UInt32 Low32bits;
		public UInt32 High32bits;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public struct TSteamGlobalUserID
	{
		public UInt16 m_SteamInstanceID;

		[StructLayout(LayoutKind.Explicit,CharSet=CharSet.Ansi,Pack=1,Size=64)]
		struct m_SteamLocalUserID
		{
			[FieldOffset(0)]
			public UInt64 As64bits;
			[FieldOffset(0)]
			public TSteamSplitLocalUserID Split;
		}
		
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=48)]
	public struct SOMsgCacheSubscribed_Item_Attrib_t
	{
		public UInt16 attribindex;
		public float value;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct CSysModule
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct CallbackManager
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct ISteamGameServerItems
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct IConCommandBaseAccessor
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct ISteamRemoteStorage
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct ISteamUtils
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct ISteamClient
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=208)]
	public struct SOMsgCacheSubscribed_Item_t
	{
		public UInt64 itemid;
		public UInt32 accountid;
		public UInt16 itemdefindex;
		public Byte itemlevel;
		public Byte itemquality;
		public UInt32 position;
		public UInt32 itemcount;
		public UInt16 attribcount;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct IVAC
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=64)]
	public struct SteamSalt
	{
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 8)]
		public Byte[] uchSalt;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct ISteam2Bridge
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct IClientUserItems
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=288)]
	public struct TSteamAppLaunchOption
	{
		public IntPtr szDesc;
		public UInt32 uMaxDescChars;
		public IntPtr szCmdLine;
		public UInt32 uMaxCmdLineChars;
		public UInt32 uIndex;
		public UInt32 uIconIndex;
		public Int32 bNoDesktopShortcut;
		public Int32 bNoStartMenuShortcut;
		public Int32 bIsLongRunningUnattended;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=160)]
	public struct LeaderboardEntry_t
	{
		public CSteamID m_steamIDUser;
		public Int32 m_nGlobalRank;
		public Int32 m_nScore;
		public Int32 m_cDetails;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=2624)]
	public struct TSteamSubscription
	{
		public IntPtr szName;
		public UInt32 uMaxNameChars;
		public IntPtr puAppIds;
		public UInt32 uMaxAppIds;
		public UInt32 uId;
		public UInt32 uNumApps;
		public EBillingType eBillingType;
		public UInt32 uCostInCents;
		public UInt32 uNumDiscounts;
		public Int32 bIsPreorder;
		public Int32 bRequiresShippingAddress;
		public UInt32 uDomesticShippingCostInCents;
		public UInt32 uInternationalShippingCostInCents;
		public bool bIsCyberCafeSubscription;
		public UInt32 uGameCode;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 255)]
		public SByte[] szGameCodeDesc;
		public bool bIsDisabled;
		public bool bRequiresCD;
		public UInt32 uTerritoryCode;
		public bool bIsSteam3Subscription;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct ISteamMasterServerUpdater
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct ISteamBilling
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=5344)]
	public struct TSteamSubscriptionReceipt
	{
		public ESteamSubscriptionStatus eStatus;
		public ESteamSubscriptionStatus ePreviousStatus;
		public ESteamSubscriptionBillingInfoType eReceiptInfoType;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 17)]
		public SByte[] szConfirmationCode;

		[StructLayout(LayoutKind.Explicit,CharSet=CharSet.Ansi,Pack=1,Size=5088)]
		struct Union
		{
			[FieldOffset(0)]
			public TSteamPaymentCardReceiptInfo PaymentCardReceiptInfo;
			[FieldOffset(0)]
			public TSteamPrepurchaseReceiptInfo PrepurchaseReceiptInfo;
		}
		
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct IClientMasterServerUpdater
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct IClientMatchmakingServers
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=2112)]
	public struct TSteamSubscriptionDiscount
	{
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 255)]
		public SByte[] szName;
		public UInt32 uDiscountInCents;
		public UInt32 uNumQualifiers;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct CNatTraversalStat
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=0)]
	public struct ISteamNetworking
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=64)]
	public struct TSteamOfflineStatus
	{
		public Int32 eOfflineNow;
		public Int32 eOfflineNextSession;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class IClientAppManager
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamApps002
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamMasterServerUpdater001
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUtils001
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUtils003
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamNetworking001
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteam003
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteam005
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteam2Bridge002
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamGameServer003
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamGameServer004
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamGameServer009
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUtils004
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUserStats002
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUserStats003
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUserItems001
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUserItems003
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUtils005
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamClient006
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamBilling001
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamClient007
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamClient008
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUserStats006
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=64)]
	public class servernetadr_t
	{
		public UInt16 m_usConnectionPort;
		public UInt16 m_usQueryPort;
		public UInt32 m_unIP;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamMatchmaking001
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamMatchmaking002
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamMatchmaking004
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamMatchmaking005
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamMatchmaking007
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamApps001
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamGameServer002
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamMatchmaking006
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamNetworking002
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class IClientUtils
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class IClientDepotBuilder
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamFriends002
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamFriends003
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamFriends004
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamFriends005
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class IClientFriends
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamMatchmakingPlayersResponse
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class IClientContentServer
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class IClientUser
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class IClientGameCoordinator
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=2912)]
	public class gameserveritem_t
	{
		public servernetadr_t m_NetAdr;
		public Int32 m_nPing;
		public bool m_bHadSuccessfulResponse;
		public bool m_bDoNotRefresh;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 32)]
		public SByte[] m_szGameDir;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 32)]
		public SByte[] m_szMap;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 64)]
		public SByte[] m_szGameDescription;
		public Int32 m_nAppID;
		public Int32 m_nPlayers;
		public Int32 m_nMaxPlayers;
		public Int32 m_nBotPlayers;
		public bool m_bPassword;
		public bool m_bSecure;
		public UInt32 m_ulTimeLastPlayed;
		public Int32 m_nServerVersion;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 64)]
		public SByte[] m_szServerName;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 128)]
		public SByte[] m_szGameTags;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteam004
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteam006
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUserStats001
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUserStats004
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUserStats005
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamMatchmakingPingResponse
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamMatchmaking003
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamGameServerItems004
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class IClientGameServer
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamGameStats001
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamFriends001
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUser012
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamMatchmakingServers002
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class IClientApps
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamContentServer001
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamContentServer002
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteam2Bridge001
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class IClientMatchmaking
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamApps003
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class IClientGameStats
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamBilling002
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUserItems002
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUserItems004
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamMatchmakingServerListResponse
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamMatchmakingRulesResponse
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class IClientEngine
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamGameCoordinator001
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUser005
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamGameServerItems002
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamGameServerItems003
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=128)]
	public class CDllDemandLoader
	{
		public IntPtr m_pchModuleName;
		public IntPtr m_hModule;
		public bool m_bLoadAttempted;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=4448)]
	public class CSteamAPILoader
	{
		public CDllDemandLoader steamservice;
		public CDllDemandLoader steamclient;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 260)]
		public SByte[] m_pchSteamDir;
		[MarshalAs(UnmanagedType.ByValArray, SizeConst = 260)]
		public SByte[] m_pchSteamDirBin;
		public bool m_bFullyInitialized;
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUtils002
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class IClientBilling
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class IP2PController
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUser004
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUser006
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUser007
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUser008
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUser009
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUser010
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUser011
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamUser013
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamRemoteStorage001
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamRemoteStorage002
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamMatchmakingServers001
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamGameServer005
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamGameServer006
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamGameServer007
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamGameServer008
	{
	}
	
	[StructLayout(LayoutKind.Sequential,CharSet=CharSet.Ansi,Pack=1,Size=32)]
	public class ISteamNetworking003
	{
	}
	
}
