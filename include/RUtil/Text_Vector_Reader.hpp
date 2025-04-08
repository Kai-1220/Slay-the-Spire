#ifndef RUTIL_TEXT_VECTOR_READER_HPP
#define RUTIL_TEXT_VECTOR_READER_HPP
#include "Draw/Text_layout.hpp"
namespace RUtil{
enum class Text_ID{
    //ui
    AbandonRunButton,AbstractCard,AbstractChest,AbstractCreature,AbstractDungeon,AbstractMonster,AbstractPlayer,AbstractPotion,AbstractRoom,AnyCardFromDeckToHandAction,ApplyPowerAction,ArmamentsAction,AscensionModeDescriptions,AscensionTextEffect,AscensionUnlockEffect,AttackFromDeckToHandAction,BattleStartEffect,BetaArtUnlockEffect,BetterToHandAction,BossChest,BossRelicSelectScreen,CacheAction,CampfireSleepEffect,CampfireSmithEffect,CampfireTokeEffect,CampfireUI,Cancel_Button,CardLibSortHeader,CardLibraryScreen,CardRewardScreen,CharacterOption,CharacterSelectScreen,ChooseOneScreen,ClarityAction,CombatRewardScreen,ConfirmPopup,Confirm_Button,CopyAction,CreditsScreen,CustomModeScreen,DailyScreen,DeathScreen,DeathScreenUi,DeletePopup,Dig_Option,DiscardAction,DiscardPilePanel,DiscardPileToHandAction,DiscardPileToTopOfDeckAction,DiscardPileViewScreen,DrawPilePanel,DrawPileViewScreen,DualWieldAction,DungeonMapScreen,DungeonTransitionScreen,EarlyAccessPopup,End_Turn_Button,ExhaustAction,ExhaustViewScreen,ExhumeAction,ExitGameButton,Exordium,ForethoughtAction,GainGoldTextEffect,GamblingChipAction,GameSavedEffect,GridCardSelectScreen,HandCardSelectScreen,HiddenChamberAction,ImmolateAction,InputSettingsScreen,LanguageDropdown,LeaderboardFilters,LeaderboardsScreen,Legend,Lift_Option,MainMenuScreen,MasterDeckViewScreen,MenuButton,MenuPanels,MerchantImageTextNotInGame,MiscConsoleStrings,OpeningAction,OptionsPanel,PatchNotesScreen,Period,PotionPopUp,PotionViewScreen,PowerExpireTextEffect,Proceed_Button,PutOnDeckAction,Recall_Option,RecycleAction,RelicViewScreen,RenamePanel,ReprieveAction,ReprogramAction,Rest_Option,RestartForChangesEffect,RetainCardsAction,RewardItem,RichPresence,RunHistoryMonsterNames,RunHistoryPathNodes,RunHistoryScreen,SaveSlot,SaveSlotScreen,SeedPanel,SettingsScreen,SetupAction,ShopRoom,SignatureMoveMessage,SingleCardViewPopup,SingleViewRelicPopup,SkillFromDeckToHandAction,Smith_Option,StorePotion,SyncMessage,TheBeyond,TheCity,TheEnding,TipHelper,Toke_Option,TopPanel,TreasureRoom,TreasureRoomBoss,TwitchVoter,UnlockCharacterScreen,UnlockScreen,UnlockTextEffect,Unlock_Confirm_Button,VictoryScreen,WishAction
};
class Text_Vector_Reader
{
public:
    Text_Vector_Reader()=delete;~Text_Vector_Reader()=delete;Text_Vector_Reader(const Text_Vector_Reader &) = delete;Text_Vector_Reader(Text_Vector_Reader &&) = delete;Text_Vector_Reader &operator=(const Text_Vector_Reader &) = delete;Text_Vector_Reader &operator=(Text_Vector_Reader &&) = delete;
    static const std::vector<std::shared_ptr<Draw::Text_layout>> &GetTextVector(const Text_ID id);
private:
    static void GetJsonFileText(const std::string &path,std::vector<std::vector<std::shared_ptr<Draw::Text_layout>>>&vec);
};
}
#endif